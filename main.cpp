/*
 * Prog Tools for Scits Engrs - CIVL 8903/7903 001
 * Prof. Ricardo Taborda
 * Homework 8 
 */

#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include <string.h>
#include <vector>
#include <list>

#include "earthquake.h"
#include "station.h"
#include "io_print_handler.h"

using namespace std;


/***************************** Function prototypes *************************************/

bool read_input(ifstream&, ofstream&, Event db[MAXSIZE], int &, int &, int &,
                int &, int &, vector<Event> &dbv);

void print_header(string, string, string, Earthquake er_info[1], ofstream&);
void generate_recorded_list(Earthquake er_info[1], ofstream&, Event db[MAXSIZE],
                            int &, int &);

void read_check_header(ifstream& inputfile, ofstream&, Earthquake er_info[1], string);

void print_summary(ofstream& errorfile, int, int, int, string);

/********************************* Main function ****************************************/

int main(int argc, char** argv) {
    
//	int num_eqs = argc-1;                 
	list< string > file_names;               
	
	for (int i = 1; i < argc; ++i) {
//		get_file_names (argv[i]);
		file_names.push_back(argv[i]);    
		
	}
	
    ofstream errorfile;
    ifstream inputfile;
    ofstream outputfile;
    
    open_output(errorfile, "logfile.log");
    
    for (list<string>::iterator it = file_names.begin(); it != file_names.end();
         it++) {
	
                string eq_file_name = *it;
		string output_fname = eq_file_name + ".out";

		string month_name, day, year;
		int total_entry = 0, invalid_counter = 0, valid_counter = 0, total_co =
				0;

		Event db[MAXSIZE];
		vector<Event> dbv(10);
		Earthquake er_info[1];
		int number_of_events;

		read_check_header(inputfile, errorfile, er_info, eq_file_name);

		print_output(errorfile, cout, "Header read correctly! \n");

		open_output(outputfile, errorfile, output_fname);

		print_header(month_name, day, year, er_info, outputfile);   //month name incorporated
		
		////////
		
		////////
        
        print_output(errorfile, cout, "==== \n\n");
        
   }
    
    print_output(errorfile, cout, "Finished All! \n\n");
    errorfile.close();
}

//////**************** Function Definition ********************************/////

void read_check_header(ifstream& inputfile, ofstream& errorfile,
		Earthquake er_info[1], string eq_file_name) {

	double t_lat, t_lon, t_depth;
	string month_name, t_event_id, t_event_name, t_event_date, t_event_time, t_time_zone,
			t_mag_t;
	float t_mag;

	open_input(inputfile, errorfile, eq_file_name);
	print_output(errorfile, cout, "Processing input ... \n");

	inputfile >> t_event_id;
	inputfile >> t_event_date;
	inputfile >> t_event_time;
	inputfile >> t_time_zone;

	inputfile.ignore();
	getline(inputfile, t_event_name);

	inputfile >> t_lon;
	inputfile >> t_lat;
	inputfile >> t_depth;

	inputfile >> t_mag_t;
	inputfile >> t_mag;

	er_info[0].set_lon(er_info, errorfile, t_lon);
	er_info[0].set_lat(er_info, errorfile, t_lat);
	er_info[0].set_depth(er_info, errorfile, t_depth);
	er_info[0].set_event_id(er_info, errorfile, t_event_id);
	er_info[0].set_event_date(er_info, errorfile, t_event_date, month_name);
	er_info[0].set_event_time(er_info, errorfile, t_event_time);
	er_info[0].set_time_zone(er_info, errorfile, t_time_zone);
	er_info[0].set_event_name(er_info, errorfile, t_event_name);
	er_info[0].set_mag_type(er_info, errorfile, t_mag_t);
	er_info[0].set_mag(er_info, errorfile, t_mag);

}

void print_header(string month_name, string day, string year, Earthquake er_info[1],
		ofstream& outputfile) {

	string lat, lon, depth, event_id, mag, event_name, magnitude, event_time,
			time_zone, mag_t;

	outputfile << "# " << day << " " << month_name
			<< " " << year << " " << er_info[0].get_event_time(er_info) << " "
			<< er_info[0].get_time_zone(er_info) << " "
			<< er_info[0].Magnitude_Type_to_string(
					er_info[0].string_to_Magnitude_Type(
							er_info[0].get_mag_type(er_info))) << " "
			<< er_info[0].get_mag(er_info) << " "
			<< er_info[0].get_event_name(er_info) << " " << "["
			<< er_info[0].get_event_id(er_info) << "]" << "("
			<< er_info[0].get_lon(er_info) << ", "
			<< er_info[0].get_lat(er_info) << ", "
			<< er_info[0].get_depth(er_info) << ")" << "\n";

}

void print_summary(ofstream& errorfile, int invalid_counter, int valid_counter,
		int total_co, string eq_file_name) {

	print_output(errorfile, cout, "Total invalid entries ignored: ");
	print_output(errorfile, cout, invalid_counter);
	print_output(errorfile, cout, "\n");

	print_output(errorfile, cout, "Total valid entries read: ");
	print_output(errorfile, cout, valid_counter);
	print_output(errorfile, cout, "\n");

	print_output(errorfile, cout, "Total signal names produced: ");
	print_output(errorfile, cout, total_co);
	print_output(errorfile, cout, "\n");
	print_output(errorfile, cout, "Finished   ");
	string input_fname1 = eq_file_name + ".in \n";
	print_output(errorfile, cout, input_fname1);
	print_output(errorfile, cout, "\n");
}

