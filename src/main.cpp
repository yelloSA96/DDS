/*
    Author: Thomas Suebwicha

    Version Control
    0.1 - Completed the integration of reading the storage
    0.2 - Introducing the Introductory display module for text 
*/

#define _CRT_SECURE_NO_WARNINGS

#include "display.h"
#include "manage.h"

#include <iostream>
#include <vector>
#include <iomanip> // Display information nicely
#include <ctime>    // Display the time 
#include <string>

using namespace std;


int displayMenu() {
    int input_num;
    cout << "Available Options: " << endl;
    cout << "   1 - Display current inventory" << endl;
    cout << "   2 - Add new item " << endl;
    cout << "   -1 - Exit the program" << endl;
    cout << "Select your option: ";
    
    cin >> input_num;

    return input_num;
}

string getDate() {
    // Want to check items based on date then 
    time_t now = time(0);
    cout << "TIme now" << now << endl;
    tm* ltm = localtime(&now);
    int day = ltm->tm_mday;
    int month = 1 + ltm->tm_mon;
    int year = 1900 + ltm->tm_year;
    /*
    cout << day << endl;
    cout << month << endl;
    cout << year << endl;
    */
    string output = to_string(day) + "." + to_string(month) + "." + to_string(year);
    return output;
}

void display_title_text() {
    system("cls");
    int version = 0.3;
    cout << "Welcome to Due Date System(DDS) text version." << endl;
    cout << "---------"+to_string(version)+"---------" << endl;
    cout << "Date is " + getDate()<<endl;
}

int main(int argc, char *argv[]){

    display_title_text();
    
    vector<vector<string>> storage;     // Storage for this system
    manage management;                  // Management Object
    management.Read_and_store(storage); // Read in storage
    //input.test_pass();
    int field_width = 20;
    int multiplier = 3*field_width;
    int userInput=0;

    while (userInput != -1) {

        userInput = displayMenu();
        switch (displayMenu()) {
        case 1:
            cout << setw(multiplier) << setfill('-') << "-" << endl;
            cout << left << setw(field_width) << setfill(' ') << "ITEM";
            cout << left << setw(field_width) << setfill(' ') << "Expected Exp. Date";
            cout << left << setw(field_width) << setfill(' ') << "Storage Type" << endl;
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
        case -1:
            cout << "Goodbye" << endl;
            break;
        default:
            cout << "Default case was called" << endl;
            break;
        }
    }


    return 0;
}
