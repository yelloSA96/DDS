/*
    Author: Thomas Suebwicha

    Version Control
    0.1 - Completed the integration of reading the storage
    0.2 - Introducing the Introductory display module for text 
*/


#include "display.h"
#include "manage.h"

#include <iostream>
#include <vector>
#include <iomanip> // Display information nicely
#include <ctime>    // Display the time 

using namespace std;

void display_title_text() {
    system("clear");
    cout << "Welcome to Due Date System(DDS) text version." << endl;
    cout << "---------Version 0.2---------" << endl;
}

int display_menu() {
    int input_num;
    cout << "Available Options: " << endl;
    cout << "   1 - Display current inventory" << endl;
    cout << "   2 - Add new item " << endl;
    cout << "Select your option: ";
    cin >> input_num;

    return input_num;
}

void update_system() {
    // Want to check items based on date then 
}


int main(int argc, char *argv[]){

    // display_title_text();
    
    vector<vector<string>> storage; // Storage for this system
    manage management;
    management.Read_and_store(storage);
    //input.test_pass();
    int field_width = 20;

    time_t now = time(0);
    cout << "TIme now" << now << endl;
    tm* ltm = localtime(&now);
    int day= ltm->tm_mday;
    int month = 1 + ltm->tm_mon;
    int year = 1900 + ltm->tm_year;
    cout << day << endl;
    cout << month << endl;
    cout << year << endl;
    
    /*
    switch (display_menu()) {
    case 1:
        cout << setw(field_width*3) << setfill('-') << "-" <<endl;
        cout << left << setw(field_width) << setfill(' ') << "ITEM";
        cout << left << setw(field_width) << setfill(' ') << "Expected Exp. Date";
        cout << left << setw(field_width) << setfill(' ') << "Storage Type"<< endl;
        for (int i = 0; i < storage.size(); i++) {
            int length = storage[i].size();
            for (int j = 0; j < length; j++) {
                cout << left << setw(field_width) << setfill(' ') << storage[i][j];
            }
            cout << endl;
        }
        break;
    case 2:
        management.Add_new_entry();
        break;
    default:
        cout << "Default case was called" << endl;
        break;
    }
    */


    return 0;
}
