#include "station.h"

Network_Code string_to_Network_Code(string s) {

	string ss = uppercase(s);

	if (ss == "CE") return CE;
	if (ss == "CI") return CI;
	if (ss == "FA") return FA;
	if (ss == "NP") return NP;
	if (ss == "WR") return WR;

	// It should never get here!!
	exit (EXIT_FAILURE);

}

string Band_Type_to_string(Band_Type c) {

	switch (c) {
	case Longperiod: return "L";
	case Shortperiod: return "B";
	case Broadband: return "H";

	}

	// It should never get here!!
	exit (EXIT_FAILURE);
}

bool Event::set_Ins_type(Event db[MAXSIZE], string Ins_type1, int total_entry, ofstream& errorfile) {

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

Instro_Type Event::get_Ins_type(Event db[MAXSIZE]) {
	return Ins_type;
}

bool Event::set_orientation(Event db[MAXSIZE], string orientation1, int total_entry, ofstream& errorfile) {

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

string Event::get_orientation(Event db[MAXSIZE]) {
	return orientation;
}

bool Event::set_nt_name(Event db[MAXSIZE], string nt_name1, int total_entry, ofstream& errorfile) {

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

Network_Code Event::get_nt_name(Event db[MAXSIZE]) {

	return nt_name;
}