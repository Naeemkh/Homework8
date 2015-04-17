#include "station.h"
#include "io_print_handler.h"



Network_Code Event::string_to_Network_Code(string s) {

	string ss = uppercase(s);

	if (ss == "CE") return CE;
	if (ss == "CI") return CI;
	if (ss == "FA") return FA;
	if (ss == "NP") return NP;
	if (ss == "WR") return WR;

	// It should never get here!!
	exit (EXIT_FAILURE);

}

string Event::Network_Code_to_string(Network_Code c) {
	switch (c) {
	case CE: return "CE";
	case CI: return "CI";
	case FA: return "FA";
	case NP: return "NP";
	case WR: return "WR";
	}
	// It should never get here!!
	exit (EXIT_FAILURE);
}

Band_Type Event::string_to_Band_Type(string s) {

	string ss = uppercase(s);

	if (ss == "LONG-PERIOD") return Longperiod;
	if (ss == "SHORT-PERIOD") return Shortperiod;
	if (ss == "BROADBAND") return Broadband;

	// It should never get here!!
	exit (EXIT_FAILURE);

}

string Event::Band_Type_to_string(Band_Type c) {

	switch (c) {
	case Longperiod: return "L";
	case Shortperiod: return "B";
	case Broadband: return "H";

	}

	// It should never get here!!
	exit (EXIT_FAILURE);
}

Instro_Type Event::string_to_instro_Type(string s) {

	string ss = uppercase(s);

	if (ss == "HIGH-GAIN")
		return HighGain;
	if (ss == "LOW-GAIN")
		return LowGain;
	if (ss == "ACCELEROMETER")
		return Accelerometer;

	// It should never get here!!
	exit(EXIT_FAILURE);

}

string Event::Instro_Type_to_string(Instro_Type c) {
	switch (c) {
	case HighGain:
		return "H";
	case LowGain:
		return "L";
	case Accelerometer:
		return "N";

	}
	// It should never get here!!
	exit(EXIT_FAILURE);
}




bool Event::set_nt_name(string nt_name1, int total_entry,
		ofstream& errorfile) {

	string ss = uppercase(nt_name1);
	if (((ss == "CE") || (ss == "CI") || (ss == "FA") || (ss == "NP")
			|| (ss == "WR")) && (ss == nt_name1)) {
		nt_name = string_to_Network_Code(nt_name1);

		return 0;
	} else {

		stringstream ks;
		string kk;
		ks << total_entry;
		ks >> kk;
		print_output(errorfile, cout, "Entry # ");
		print_output(errorfile, cout, kk);
		print_output(errorfile, cout, " Ignored. ");
		print_output(errorfile, cout, "Invalid Network. \n");

		return 1;
	}
}

Network_Code Event::get_nt_name() {

	return nt_name;
}

bool Event::set_st_name( string st_name1, int total_entry,
		ofstream& errorfile) {

	bool st_flag = 0;
	string ss = uppercase(st_name1);
	int sn = st_name1.size();

	stringstream st_sst;
	int st_in;
	string st_string;

	st_sst << st_name1;
	st_sst >> st_in;
	st_sst << st_in;
	st_sst >> st_string;

	if (sn == 3 && ss == st_name1 && st_string == "") {
		st_flag = 1;
	}
	if (sn == 5) {
		st_flag = 1;
		for (int i = 0; i == 4; i++) {
			if (isdigit(st_name1[i] == 0)) {
				st_flag = 0;
			}
		}
	}

	if (st_flag == 1) {
		st_name = st_name1;

		return 0;

	} else {
		stringstream ks;
		string kk;
		ks << total_entry;
		ks >> kk;

		print_output(errorfile, cout, "Entry # ");
		print_output(errorfile, cout, kk);
		print_output(errorfile, cout, " Ignored. ");
		print_output(errorfile, cout, "Invalid station code. \n");

		return 1;

	}
}

string Event::get_st_name() {
	return st_name;
}

bool Event::set_Ins_type( string Ins_type1, int total_entry, ofstream& errorfile) {

	string ss = uppercase(Ins_type1);

	if ((ss == "HIGH-GAIN") || (ss == "LOW-GAIN") || (ss == "ACCELEROMETER")) {

		Ins_type = string_to_instro_Type(Ins_type1);

		return 0;
	} else {

		stringstream ks;
		string kk;
		ks << total_entry;
		ks >> kk;
		print_output(errorfile, cout, "Entry # ");
		print_output(errorfile, cout, kk);
		print_output(errorfile, cout, " Ignored. ");
		print_output(errorfile, cout, "Invalid instrument type. \n");

		return 1;
	}

}

Instro_Type Event::get_Ins_type() {
	return Ins_type;
}

bool Event::set_b_type(string b_type1, int total_entry, ofstream& errorfile) {

	string ss = uppercase(b_type1);
	if ((ss == "LONG-PERIOD") || (ss == "SHORT-PERIOD")
			|| (ss == "BROADBAND")) {

		b_type = string_to_Band_Type(b_type1);

		return 0;
	} else {

		stringstream ks;
		string kk;
		ks << total_entry;
		ks >> kk;

		print_output(errorfile, cout, "Entry # ");
		print_output(errorfile, cout, kk);
		print_output(errorfile, cout, " Ignored. ");
		print_output(errorfile, cout, "Invalid band type. \n");

		return 1;
	}
}

Band_Type Event::get_band_type() {
	return b_type;
}

bool Event::set_orientation( string orientation1, int total_entry, ofstream& errorfile) {

	bool or_flag = 0;
	int kk = 1;
	int ors = orientation1.size();

	if (ors < 4 && ors > 0) {
		if (isdigit(orientation1[0])) {
			for (int i = 0; i < ors; i++) {
				if (strncmp(&orientation1[i], "1", 1) == 0
					|| strncmp(&orientation1[i], "2", 1) == 0
					|| strncmp(&orientation1[i], "3", 1) == 0) {
						kk = kk + 1;
				}
			}
		} else {

			for (int i = 0; i < ors; i++) {
				if (strncmp(&orientation1[i], "N", 1) == 0
					|| strncmp(&orientation1[i], "E", 1) == 0
					|| strncmp(&orientation1[i], "Z", 1) == 0) {
						kk = kk + 1;
				}
			}
		}
	}

	if (kk - 1 == ors) {
		or_flag = 1;
	}
	if (ors == 2 && orientation1[0] == orientation1[1]) {
		or_flag = 0;
	}
	if (ors == 2
		&& (orientation1[0] == orientation1[1]
	|| orientation1[0] == orientation1[2]
	|| orientation1[1] == orientation1[2])) {
		or_flag = 0;
	}

	if (or_flag == 1) {
		orientation = orientation1;

		return 0;
	} else {
		stringstream ks;
		string kk;
		ks << total_entry;
		ks >> kk;
		print_output(errorfile, cout, "Entry # ");
		print_output(errorfile, cout, kk);
		print_output(errorfile, cout, " Ignored. ");
		print_output(errorfile, cout, "Invalid orientation. \n");

		return 1;
	}

}

string Event::get_orientation() {
	return orientation;
}
