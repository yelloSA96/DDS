/*
	Author - Thomas Suebwicha

	Version Control

	0.1 Completed the text parser
	0.2 Completed the Add new entry module
	0.3 

*/




#include "manage.h"
#include <fstream>
#include <sstream>
#include <vector>

#include <iostream>

using namespace std;

void manage::Read_and_store(vector<vector<string>>& Input) {
	
	fstream tunnel;
	tunnel.open("storage.txt",fstream::in);
	
	// Check if file exists and display error if not. 
	if (!tunnel) {
		cerr << "Unable to open the text file 'storage.txt'!";
		exit(1);	// Calls System to stop!
	}

	if ( !tunnel.eof() ) {

		string line;
		string partial_string;
		stringstream break_up;
		while (tunnel >> line) {
			// Break down information
			// cout << " This is the line - "<< line << endl;
			break_up << line;
			vector<string> Row;
			while (getline(break_up, partial_string, ',')) {
				//			cout << "Partial_string - " << partial_string << endl;
				Row.push_back(partial_string);
			}
			Input.push_back(Row);
			break_up.clear();

		}
		tunnel.close();
	}
/*
	cout << "Reading Vector entries" << endl;
	for (int i = 0; i < Input.size(); i++) {
		int length = Input[i].size();
		for (int j = 0; j < length; j++) {
			cout << Input[i][j] << endl;
		}
	}
*/	

	cout << "Completed Reading the Database." << endl;
}

void manage::Add_new_entry() {
	ofstream output_connection;
	output_connection.open("storage.txt",fstream::app);

	cout << "New Entry Module" << endl;
	cout << "What is the item called?(Bread) ";
	string item_name;
	cin >> item_name;

	cout << "What is the expected due/best before date?(DD/MM/YYYY) ";
	string item_date;
	cin >> item_date;

	cout << "Where was it stored? (Fridge, Pantry) ";
	string storage_type;
	cin >> storage_type;

	string line = item_name + "," + item_date + "," + storage_type+"\n";
	output_connection << line;
	output_connection.close();

}

void manage::delete_entry() {
	// It will scan through a file line by line and copy it to a temp file 
	// It will be renamed to be the new storage 
	fstream temp;
}


void manage::test_pass() {
	cout << " Started test_pass function" << endl;
	

}