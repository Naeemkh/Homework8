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


////A FUNCTION THAT CAN PRINT THE INPUT FILE NAMES
//
//void get_file_names (const char* filename) { 
//	
//	cout << filename << endl;
//} 


/***************************** function prototypes *************************************/

bool read_input(ifstream&, ofstream&, Event db[MAXSIZE], int &, int &, int &,
                int &, int &, vector<Event> &dbv);

void print_header(int, int, int, Earthquake er_info[1], ofstream&);
void generate_recorded_list(Earthquake er_info[1], ofstream&, Event db[MAXSIZE],
                            int &, int &);

void read_check_header(ifstream& inputfile, ofstream&, Earthquake er_info[1],
                       int &, int&, int&, string);

void print_summary(ofstream& errorfile, int, int, int, string);

months int_to_months(int);

string uppercase(string &);



//MAIN FUNCTION STARTS HERE

int main(int argc, char** argv) {
    
    
	
//	int num_eqs = argc-1;                 //Declaring & Getting number of earthquakes
	list< string > file_names;               //Declaring input file names
	
	for (int i = 1; i < argc; ++i) {
//		get_file_names (argv[i]);
		file_names.push_back(argv[i]);    //Storing file names in a list
		
	}
	
	
	// Now each file name like file_names[1] or file_names[2] ..... can work as individual input file
	// Also we got a variable of number of earthquakes as num_eqs
	
	//.......
	
	// Here We can process each job with each file name .. file_names[].
	
    //..........
	
    return 0;
}
