/*
 * Prog Tools for Scits Engrs - CIVL 8903/7903 001
 * Prof. Ricardo Taborda
 * Homework 8 
 */

#include <iostream>
#include <list>

using namespace std;


//A FUNCTION THAT CAN PRINT THE INPUT FILE NAMES

void get_file_names (const char* filename) { 
	
	cout << filename << endl;
} 



//MAIN FUNCTION STARTS HERE

int main(int argc, char** argv) {
	
	int num_eqs = argc-1;                 //Declaring & Getting number of earthquakes
	list<char*> file_names;               //Declaring input file names
	
	for (int i = 1; i < argc; ++i) {
		get_file_names (argv[i]);
		file_names.push_back(argv[i]);    //Storing file names in a list
		
	}
	
	
	// Now each file name like file_names[1] or file_names[2] ..... can work as individual input file
	// Also we got a variable of number of earthquakes as num_eqs
	
	//.......
	
	// Here We can process each job with each file name .. file_names[].
	
    //..........
	
	
}
