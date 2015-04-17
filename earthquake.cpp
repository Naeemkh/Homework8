#include "earthquake.h"

int Earthquake::set_lat(Earthquake er_info[1], ofstream& errorfile,
                        double lat1) {
    if (-60 <= lat1 && lat1 <= 60) {
        lat = lat1;
        return 0;
    } else {
        print_output(errorfile, cout, "Latitude is not valid. \n");
        return 1;
    }
}

double Earthquake::get_lat(Earthquake er_info[1]) {
    return lat;
}

int Earthquake::set_lon(Earthquake er_info[1], ofstream& errorfile,
                        double lon1) {
    if (-180 <= lon1 && lon1 <= 180) {
        lon = lon1;
        return 0;
    } else {
        print_output(errorfile, cout, "Longitude is not valid. \n");
        return 1;
    }
}

double Earthquake::get_lon(Earthquake er_info[1]) {
    return lon;
}

int Earthquake::set_depth(Earthquake er_info[1], ofstream& errorfile,
                          double depth1) {
    if (0 <= depth1) {
        depth = depth1;
        return 0;
    } else {
        print_output(errorfile, cout, "Depth of earthquake is not valid. \n");
        return 1;
        
    }
}

double Earthquake::get_depth(Earthquake er_info[1]) {
    return depth;
}

void Earthquake::set_event_id(Earthquake er_info[1], ofstream& errorfile,
                              string event_id1) {
    
    event_id = event_id1;
}

string Earthquake::get_event_id(Earthquake er_info[1]) {
    return event_id;
}

int Earthquake::set_event_date(Earthquake er_info[1], ofstream& errorfile,
                               string event_date1, int &month, int &day, int &year) {
    
    int s = event_date1.size();
    int k = 0, delim;
    int pos[2] = { 0 };
    bool date_flag = 0;
    
    int p1 = event_date1.find("/");
    int p2 = event_date1.find("-");
    
    if (p1 < 0 && (p2 < 0)) {
        date_flag = 1;
    } else if (p1 > 0 && p2 > 0) {
        date_flag = 1;
    } else if (p1 > 0 && p2 < 0) {
        delim = 1;
    } else if (p1 < 0 && p2 > 0) {
        delim = 2;
    }
    
    if (date_flag == 0) {
        
        for (int i = 0; i < s; i++) {
            switch (delim) {
                case 1:
                    if (strncmp(&event_date1[i], "/", 1) == 0) {
                        pos[k] = i;
                        k = k + 1;
                    }
                    break;
                case 2:
                    if (strncmp(&event_date1[i], "-", 1) == 0) {
                        pos[k] = i;
                        k = k + 1;
                    }
                    break;
            }
        }
    }
    
    if (k != 2) {
        date_flag = 1;
    } else {
        stringstream m, d, y;
        
        m << event_date1.substr(0, pos[0]);
        d << event_date1.substr(pos[0] + 1, pos[1] - pos[0] - 1);
        y << event_date1.substr(pos[1] + 1, s - pos[1]);
        
        m >> month;
        d >> day;
        y >> year;
        
        if (month < 0 || month > 12) {
            date_flag = 1;
        }
        if (day < 0 || day > 31) {
            date_flag = 1;
        }
        if (year < 1900 || year > 2015) {
            date_flag = 1;
        }
    }
    
    if (date_flag == 0) {
        
        event_date = event_date1;
        return 0;
    } else {
        print_output(errorfile, cout, "Date format is not valid. \n");
        return 1;
        
    }
}

string Earthquake::get_event_date(Earthquake er_info[1]) {
    return event_date;
}

int Earthquake::set_event_time(Earthquake er_info[1], ofstream& errorfile,
                               string event_time1) {
    
    int s = event_time1.size();
    int k = 0;
    int pos[2] = { 0 };
    bool time_flag = 0;
    
    int p1 = event_time1.find(":");
    int p2 = event_time1.find(".");
    
    if (p1 < 0 && (p2 < 0)) {
        time_flag = 1;
    }
    if (time_flag == 0) {
        
        for (int i = 0; i < s; i++) {
            if (strncmp(&event_time1[i], ":", 1) == 0) {
                pos[k] = i;
                k = k + 1;
            }
        }
    }
    
    if (k != 2 || pos[1] > p2) {
        time_flag = 1;
    } else {
        
        stringstream hh;
        stringstream mm;
        stringstream ss;
        
        int hour, min;
        double second;
        
        hh << event_time1.substr(0, pos[0]);
        mm << event_time1.substr(pos[0] + 1, pos[1] - pos[0] - 1);
        ss << event_time1.substr(pos[1] + 1, s - pos[1]);
        
        hh >> hour;
        mm >> min;
        ss >> second;
        
        if (hour < 0 || hour > 24) {
            time_flag = 1;
        }
        if (min < 0 || min > 59) {
            time_flag = 1;
        }
        if (second < 0 || second >= 60) {
            time_flag = 1;
        }
    }
    
    if (time_flag == 0) {
        event_time = event_time1;
        return 0;
    } else {
        print_output(errorfile, cout, "Time format is not valid. \n");
        return 1;
    }
}

string Earthquake::get_event_time(Earthquake er_info[1]) {
    return event_time;
}

int Earthquake::set_time_zone(Earthquake er_info[1], ofstream& errorfile,
                              string time_zone1) {
    
    int s = time_zone1.size();
    stringstream os1;
    bool tzone_flag = 0;
    
    if (s != 3) {
        tzone_flag = 1;
    }
    
    if (tzone_flag == 0) {
        time_zone = time_zone1;
        return 0;
    } else {
        
        print_output(errorfile, cout, "Time zone format is not valid. \n");
        return 1;
        
    }
    
}

string Earthquake::get_time_zone(Earthquake er_info[1]) {
    return time_zone;
}

void Earthquake::set_event_name(Earthquake er_info[1], ofstream& errorfile,
                                string event_name1) {
    
    event_name = event_name1;
}

string Earthquake::get_event_name(Earthquake er_info[1]) {
    return event_name;
}

int Earthquake::set_mag_type(Earthquake er_info[1], ofstream& errorfile,
                             string mag_t1) {
    
    string ss = uppercase(mag_t1);
    if ((ss == "ML") || (ss == "MS") || (ss == "MB") || (ss == "MW")) {
        mag_t = mag_t1;
        return 0;
    } else {
        print_output(errorfile, cout, "Magnitude type is not valid. \n");
        return 1;
    }
    
}

string Earthquake::get_mag_type(Earthquake er_info[1]) {
    return mag_t;
}

int Earthquake::set_mag(Earthquake er_info[1], ofstream& errorfile,
                        float mag1) {
    if (mag1 >= 0) {
        mag = mag1;
        return 0;
    } else {
        print_output(errorfile, cout, "Magnitude is not in valid range. \n");
        return 1;
    }
}

float Earthquake::get_mag(Earthquake er_info[1]) {
    return mag;
}

string Earthquake::Magnitude_Type_to_string(Magnitude_Type c) {
    switch (c) {
        case ML:
            return "ML";
        case Ms:
            return "Ms";
        case Mb:
            return "Mb";
        case Mw:
            return "Mw";
    }
    // It should never get here!!
    exit (EXIT_FAILURE);
}

Magnitude_Type Earthquake::string_to_Magnitude_Type(string s) {
    
    string ss = uppercase(s);
    
    if (ss == "ML")
        return ML;
    if (ss == "MS")
        return Ms;
    if (ss == "MB")
        return Mb;
    if (ss == "MW")
        return Mw;
    
    // It should never get here!!
    exit (EXIT_FAILURE);
}

