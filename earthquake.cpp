#include "earthquake.h"

void Earthquake::set_lat(Earthquake er_info[1], ofstream& errorfile,
		double lat1) {
	if (-60 <= lat1 && lat1 <= 60) {
		lat = lat1;
	} else {
		print_output(errorfile, cout, "Latitude is not valid. \n");
		errorfile.close();
		break; // This break should exit from a earthquake file, not from the program. Needs farther check whether it works !
	}
}

double Earthquake::get_lat(Earthquake er_info[1]) {
	return lat;
}

void Earthquake::set_lon(Earthquake er_info[1], ofstream& errorfile,
		double lon1) {
	if (-180 <= lon1 && lon1 <= 180) {
		lon = lon1;
	} else {
		print_output(errorfile, cout, "Longitude is not valid. \n");
		errorfile.close();
		break;
	}
}

double Earthquake::get_lon(Earthquake er_info[1]) {
	return lon;
}

void Earthquake::set_depth(Earthquake er_info[1], ofstream& errorfile,
		double depth1) {
	if (0 <= depth1) {
		depth = depth1;
	} else {
		print_output(errorfile, cout, "Depth of earthquake is not valid. \n");
		errorfile.close();
		break;
	}
}

double Earthquake::get_depth(Earthquake er_info[1]) {
	return depth;
}

void Earthquake::set_event_id(Earthquake er_info[1], ofstream& errorfile, string line) {
	event_id = line;
}

string Earthquake::get_event_id(Earthquake er_info[1]) {
	return event_id;
}

void Earthquake::set_event_date(Earthquake er_info[1], ofstream& errorfile, string event_date1) {

	int dd, yyyy, mm;
	string month, day, year;
	stringstream month1, day1, year1;

	// Check for the date format (it must be mm/dd/year or mm-dd-year and 10 digits)

	if (event_date1.length() == 10) {

		month = event_date1.substr(0, 2);
		month1 << month;
		month1 >> mm;

		day = event_date1.substr(3, 2);
		day1 << day;
		day1 >> dd;

		year = event_date1.substr(6, 4);
		year1 << year;
		year1 >> yyyy;

		if (!isdigit(event_date1[0]) || !isdigit(event_date1[1]) || !isdigit(event_date1[3]) || !isdigit(event_date1[4])) {
			print_output(errorfile, cout, "Error: Date of earthquake is not valid. \n");
			errorfile.close();
			exit (EXIT_FAILURE);
		}

		if (!isdigit(event_date1[6]) || !isdigit(event_date1[7]) || !isdigit(event_date1[8]) || !isdigit(event_date1[9])) {
			print_output(errorfile, cout, "Error: Date of earthquake is not valid. \n");
			errorfile.close();
			exit (EXIT_FAILURE);
		} else {
			if (mm < 1 || mm > 12 || dd < 1 || dd > 31 || yyyy < 1850 || yyyy > 2016) {
				print_output(errorfile, cout, "Error: Date digits are not valid. \n");
				errorfile.close();
				exit(EXIT_FAILURE);
			}
		}

		if ((event_date1[2] != '/' || event_date1[5] != '/') && (event_date1[2] != '-' || event_date1[5] != '-')) {
			print_output(errorfile, cout, "Error: Date format is not valid. \n");
			errorfile.close();
			exit (EXIT_FAILURE);
		} else {
			event_date = event_date1;
		}

	} else {
		print_output(errorfile, cout, "Error: Date of earthquake is not valid. \n");
		errorfile.close();
		exit (EXIT_FAILURE);
	}
}

string Earthquake::get_event_date(Earthquake er_info[1]) {
	return event_date;
}

void Earthquake::set_event_time(Earthquake er_info[1], ofstream& errorfile, string event_time1) {

	int hr, min;
	float  sec = 0;
	string hour, minute, second;
	stringstream hr1, min1, sec1;
	//earthquake eq_info;

	// Check for the time format (must be hh:mm:ss.fff and 12 digits)

	if (event_time1.length() == 12) {

		hour = event_time1.substr(0, 2);
		hr1 << hour;

		hr1 >> hr;
		minute = event_time1.substr(3, 2);
		min1 << minute;
		min1 >> min;
		second = event_time1.substr(6, 2);
		sec1 << second;
		sec1 >> sec;

		//cout << "hr : " << hr << "min :" << min << "sec : " << sec <<"\n";
		//  Meanwhile the hour, minute, second should be valid numbers

		if (!isdigit(event_time1[0]) || !isdigit(event_time1[1]) || !isdigit(event_time1[3]) || !isdigit(event_time1[4])) {
			print_output(errorfile, cout, "Error: time of earthquake is not valid. \n");
			errorfile.close();
			exit (EXIT_FAILURE);
		}

		if (!isdigit(event_time1[6]) || !isdigit(event_time1[7]) || !isdigit(event_time1[9]) || !isdigit(event_time1[10]) || !isdigit(event_time1[11])) {
			print_output(errorfile, cout, "Error: time of earthquake is not valid. \n");
			errorfile.close();
			exit (EXIT_FAILURE);
		}

		if (hr < 0 || hr > 24 || min < 0 || min > 60 || sec < 0.0009 || sec > 59.9999) {
			print_output(errorfile, cout, "Error: time digits are not valid. \n");
			errorfile.close();
			exit (EXIT_FAILURE);
		}
		if (event_time1[2] != ':' || event_time1[5] != ':' || event_time1[8] != '.') {
			print_output(errorfile, cout, "Error: time format is not valid. \n");
			errorfile.close();
			exit (EXIT_FAILURE);
		}

		event_time = event_time1;

	} else {
		print_output(errorfile, cout, "Error: time of earthquake is not valid. \n");
		errorfile.close();
		exit (EXIT_FAILURE);
	}

}

string Earthquake::get_event_time(Earthquake er_info[1]) {
	return event_time;
}

void Earthquake::set_mag(Earthquake er_info[1], ofstream& errorfile, float mag1) {

	if (mag1 < 0) {
		print_output(errorfile, cout, "Error: The magnitude_size is not valid \n");
		errorfile.close();
		exit (EXIT_FAILURE);
	} else {
		mag = mag1;
	}
}

float Earthquake::get_mag(Earthquake er_info[1]) {
	return mag;
}

months int_to_months(int a) {

	if (a == 1) return January;
	if (a == 2) return February;
	if (a == 3) return March;
	if (a == 4) return April;
	if (a == 5) return May;
	if (a == 6) return June;
	if (a == 7) return July;
	if (a == 8) return August;
	if (a == 9) return September;
	if (a == 10) return October;
	if (a == 11) return November;
	if (a == 12) return December;

	// It should never get here!!
	exit (EXIT_FAILURE);
}
