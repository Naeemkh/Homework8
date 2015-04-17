#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include <string.h>
#include "io_print_handler.h"

using namespace std;

enum months {
	January = 1,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	October,
	November,
	December
};

enum Magnitude_Type {
	ML, Ms, Mb, Mw
};

class Earthquake {

public:
	int set_lat(Earthquake er_info[1], ofstream&, double);
	int set_lon(Earthquake er_info[1], ofstream&, double);
	int set_depth(Earthquake er_info[1], ofstream&, double);
	void set_event_id(Earthquake er_info[1], ofstream&, string);
	int set_event_date(Earthquake er_info[1], ofstream&, string, int &, int &,
			int &);
	int set_event_time(Earthquake er_info[1], ofstream&, string);

	int set_time_zone(Earthquake er_info[1], ofstream&, string);
	void set_event_name(Earthquake er_info[1], ofstream&, string);
	int set_mag_type(Earthquake er_info[1], ofstream&, string);
	int set_mag(Earthquake er_info[1], ofstream&, float);
        Magnitude_Type string_to_Magnitude_Type(string);


	double get_lat(Earthquake er_info[1]);
	double get_lon(Earthquake er_info[1]);
	double get_depth(Earthquake er_info[1]);

	string get_event_id(Earthquake er_info[1]);
	string get_event_date(Earthquake er_info[1]);
	string get_event_time(Earthquake er_info[1]);
	string get_time_zone(Earthquake er_info[1]);
	string get_event_name(Earthquake er_info[1]);
	string get_mag_type(Earthquake er_info[1]);
	float get_mag(Earthquake er_info[1]);

        string uppercase(string &);
	string Magnitude_Type_to_string(Magnitude_Type);

private:
bool is_date_valid(string event_date, int & month, int & day, int & year);
	double lat;
	double lon;
	double depth;
	string event_id;
	string event_date;
	string event_time;
	string time_zone;
	string event_name;
	string mag_t;
	float mag;

};
