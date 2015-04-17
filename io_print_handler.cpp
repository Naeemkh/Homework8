#include "io_print_handler.h"

void print_output(ofstream & output1, ostream & output2, string string1) {
    
    output1 << string1;
    output2 << string1;
}

void print_output(ofstream & output1, ostream & output2, int string1) {
    
    output1 << string1;
    output2 << string1;
}

void open_input(ifstream & inputfile, ofstream & errorfile, string filename) {
    
    string input_fname = filename + ".in";
    inputfile.open(input_fname.c_str());
    
    if (!inputfile.is_open()) {
        
        print_output(errorfile, cout, "Cannot open input file: ");
        print_output(errorfile, cout, input_fname);
        print_output(errorfile, cout, "\n");
        
        exit(1);
    } else {
        
        print_output(errorfile, cout, "Opening file: ");
        print_output(errorfile, cout, input_fname);
        print_output(errorfile, cout, "\n");
    }
}

void open_output(ofstream& outputfile, ofstream& errorfile,
                 string outputfilename) {
    
    outputfile.open(outputfilename.c_str());
    if (!outputfile.is_open()) {
        
        print_output(errorfile, cout, "Cannot open input file: ");
        print_output(errorfile, cout, outputfilename);
        print_output(errorfile, cout, "\n");
        
        exit(1);
    }
}

void open_output(ofstream& errorfile, string errorfilename) {
    
    errorfile.open(errorfilename.c_str());
    if (!errorfile.is_open()) {
        
        cout << "Cannot open error file: " << errorfilename;
        
    }
}

string uppercase(string & s) {
    string result = s;
    for (int i = 0; i < (int) result.size(); i++)
        result[i] = toupper(result[i]);
    return result;
}

