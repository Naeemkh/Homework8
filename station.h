#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include <string.h>
#include "io_print_handler.h"
#include "input_validate.h"

using namespace std;

const int MAXSIZE = 300;

enum Network_Code {
	CE, CI, FA, NP, WR
};

enum Band_Type {
	Longperiod, Shortperiod, Broadband
};

enum Instro_Type {
	HighGain, LowGain, Accelerometer
};

class Event {

public:
        bool set_nt_name(string, int, ofstream&);
	bool set_st_name(string, int, ofstream&);
	bool set_b_type(string, int, ofstream&);
	bool set_Ins_type(string, int, ofstream&);
	bool set_orientation(string, int, ofstream&);


	Network_Code get_nt_name();
        string get_st_name();
	Band_Type get_band_type();
	Instro_Type get_Ins_type();
	string get_orientation();


	string Network_Code_to_string(Network_Code c);
	Network_Code string_to_Network_Code(string);
	string Instro_Type_to_string(Instro_Type c);
	string Band_Type_to_string(Band_Type c);
	Band_Type string_to_Band_Type(string);
	Instro_Type string_to_instro_Type(string);
	
	string uppercase(string &);

private:
	Network_Code nt_name;
	string st_name;
	Band_Type b_type;
	Instro_Type Ins_type;
	string orientation;
};
