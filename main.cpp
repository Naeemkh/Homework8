/*
 * Prog Tools for Scits Engrs - CIVL 8903/7903 001
 * Prof. Ricardo Taborda
 * Homework 8
 */

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

/***************************** function prototypes *************************************/

bool read_input(ifstream&, ofstream&, int &, int &, int &, int &, int &,
                vector<Event *> &dbv);

void print_header(int, int, int, Earthquake er_info[1], ofstream&);
void generate_recorded_list(Earthquake er_info[1], ofstream&, int &, int &,
                            vector<Event *> &dbv);

int read_check_header(ifstream& inputfile, ofstream&, Earthquake er_info[1],
                      int &, int&, int&, string);

void print_summary(ofstream& errorfile, int, int, int, string);

months int_to_months(int);

/********************************* main function ****************************************/

int main(int argc, char** argv) {
    
    list<string> file_names;
    
    for (int i = 1; i < argc; ++i) {
        
        file_names.push_back(argv[i]);    //Storing file names in a list
        
    }
    
    ofstream errorfile;
    ifstream inputfile;
    ofstream outputfile;
    
    open_output(errorfile, "errorfile.log");
    
    for (list<string>::iterator it = file_names.begin(); it != file_names.end();
         it++) {
        
        string eq_file_name = *it;
        string output_fname = eq_file_name + ".out";
        
        int month = 0, day = 0, year = 0;
        int total_entry = 0, invalid_counter = 0, valid_counter = 0, total_co =
        0;
        
        vector<Event*> dbv;
        Earthquake er_info[1];
        int number_of_events;
        
        int file_correct = read_check_header(inputfile, errorfile, er_info,
                                             month, day, year, eq_file_name);
        
        if (file_correct == 1) {
            //errorfile.close();
            
            print_output(errorfile, cout, "Finished   ");
            string input_fname1 = eq_file_name + ".in \n";
            print_output(errorfile, cout, input_fname1);
            print_output(errorfile, cout, "\n");
            print_output(errorfile, cout, "==== \n\n");
            inputfile.close();
            
            continue;
            
        }
        
        print_output(errorfile, cout, "Header read correctly! \n");
        
        open_output(outputfile, errorfile, output_fname);
        
        print_header(month, day, year, er_info, outputfile);
        
        read_input(inputfile, errorfile, number_of_events, total_co,
                   invalid_counter, total_entry, valid_counter, dbv);
        
        print_summary(errorfile, invalid_counter, valid_counter, total_co,
                      eq_file_name);
        
        generate_recorded_list(er_info, outputfile, number_of_events, total_co,
                               dbv);
        
        inputfile.close();
        outputfile.close();
        
        print_output(errorfile, cout, "==== \n\n");
        
    }
    
    print_output(errorfile, cout, "Finished All! \n\n");
    errorfile.close();
    
}

//////**************** Function Definition ********************************/////

int read_check_header(ifstream& inputfile, ofstream& errorfile,
                      Earthquake er_info[1], int &month, int &day, int &year,
                      string eq_file_name) {
    
    double t_lat, t_lon, t_depth;
    string t_event_id, t_event_name, t_event_date, t_event_time, t_time_zone,
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
    
    bool lon_flag = er_info[0].set_lon(er_info, errorfile, t_lon);
    bool lat_flag = er_info[0].set_lat(er_info, errorfile, t_lat);
    bool depth_flag = er_info[0].set_depth(er_info, errorfile, t_depth);
    er_info[0].set_event_id(er_info, errorfile, t_event_id);
    bool date_flag = er_info[0].set_event_date(er_info, errorfile, t_event_date,
                                               month, day, year);
    bool time_flag = er_info[0].set_event_time(er_info, errorfile,
                                               t_event_time);
    bool tzone_flag = er_info[0].set_time_zone(er_info, errorfile, t_time_zone);
    er_info[0].set_event_name(er_info, errorfile, t_event_name);
    bool mt_flag = er_info[0].set_mag_type(er_info, errorfile, t_mag_t);
    bool mag_flag = er_info[0].set_mag(er_info, errorfile, t_mag);
    
    if ((lon_flag == 0) && (lat_flag == 0) && (depth_flag == 0)
        && (date_flag == 0) && (time_flag == 0) && (tzone_flag == 0)
        && (mt_flag == 0) && (mag_flag == 0)) {
        
        return 0;
        
    } else {
        
        return 1;
        
    }
    
}

months int_to_months(int a) {
    
    if (a == 1)
        return January;
    if (a == 2)
        return February;
    if (a == 3)
        return March;
    if (a == 4)
        return April;
    if (a == 5)
        return May;
    if (a == 6)
        return June;
    if (a == 7)
        return July;
    if (a == 8)
        return August;
    if (a == 9)
        return September;
    if (a == 10)
        return October;
    if (a == 11)
        return November;
    if (a == 12)
        return December;
    
    // It should never get here!!
    exit(EXIT_FAILURE);
}

string month_to_string(months c) {
    switch (c) {
        case January:
            return "January";
        case February:
            return "February";
        case March:
            return "March";
        case April:
            return "April";
        case May:
            return "May";
        case June:
            return "June";
        case July:
            return "July";
        case August:
            return "August";
        case September:
            return "September";
        case October:
            return "October";
        case November:
            return "November";
        case December:
            return "December";
    }
    // It should never get here!!
    exit(EXIT_FAILURE);
}

void print_header(int month, int day, int year, Earthquake er_info[1],
                  ofstream& outputfile) {
    
    string lat, lon, depth, event_id, mag, event_name, magnitude, event_time,
    time_zone, mag_t;
    
    outputfile << "# " << day << " " << month_to_string(int_to_months(month))
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

bool read_input(ifstream& inputfile, ofstream& errorfile, int & size,
                int & total_co, int & invalid_counter, int & total_entry,
                int & valid_counter, vector<Event *> &dbv) {
    
    string nt_name, st_name, b_type, Ins_type, orientation;
    stringstream os1;
    size = 0;
    total_entry = 1;
    Event temp_db;
    
    while (inputfile >> nt_name >> st_name >> b_type >> Ins_type >> orientation) {
        Event *temp_dbv = new Event;
        
        bool network_flag = (*temp_dbv).set_nt_name(nt_name, total_entry,
                                                    errorfile);
        bool station_flag = (*temp_dbv).set_st_name(st_name, total_entry,
                                                    errorfile);
        bool band_flag = (*temp_dbv).set_b_type(b_type, total_entry, errorfile);
        bool instrument_flag = (*temp_dbv).set_Ins_type(Ins_type, total_entry,
                                                        errorfile);
        
        bool orientation_flag = (*temp_dbv).set_orientation(orientation,
                                                            total_entry, errorfile);
        
        if ((network_flag == 0) && (station_flag == 0) && (band_flag == 0)
            && (instrument_flag == 0) && (orientation_flag == 0)) {
            
            dbv.push_back(temp_dbv);
            
            total_co = total_co + orientation.size();
            
        } else {
            
            invalid_counter = invalid_counter + 1;
            
        }
        
        total_entry++;
        
    }
    
    valid_counter = total_entry - invalid_counter - 1;
    return true;
}

void generate_recorded_list(Earthquake er_info[1], ofstream& outputfile,
                            int & size, int & total_co, vector<Event *> &dbv) {
    
    string event_id, nt_name, orientation, st_name, b_type, Ins_type;
    
    outputfile << total_co << "\n";
    
    for (vector<Event *>::iterator it = dbv.begin(); it != dbv.end(); it++) {
        
        int sc = (*it)->get_orientation().size();
        
        for (int j = 0; j < sc; j++) {
            outputfile << er_info[0].get_event_id(er_info) << "."
            << (*it)->Network_Code_to_string((*it)->get_nt_name())
            << "." << (*it)->get_st_name() << "."
            << (*it)->Band_Type_to_string((*it)->get_band_type())
            << (*it)->Instro_Type_to_string((*it)->get_Ins_type())
            << (*it)->get_orientation()[j] << "\n";
            
        }
        
    }
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

