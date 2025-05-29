//I want to improve this for myself eventually

//Add the ability to delete specific entries
//Implement entry editing functionality
//Create backup copies of the journal file
//Add entry categories or tags

#include <iostream>
#include <limits>
#include <cstdio>
#include <sstream>
#include <string>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <vector>
using namespace std;

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}


int getIntInput() {
    int value;
    while (!(cin >> value)) {
        cout << "Invalid input. Please enter a number: ";
        clearInputBuffer();
    }
    clearInputBuffer();
    return value;
}


//Displays entries by getting each line and printing
void displayEntries (){
    ifstream inFile("journal.txt");
    if (!inFile) {
        cerr << " -- Unable to open file -- " << endl;
        return;
    }

    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }

    if (inFile.eof()) {
        cout << "\n\n-- End of File -- " << endl;
    } else {
        cout << " -- Error occurred while reading file -- " << endl;
    }

    inFile.close();
    return;

}

//Adds entries by appending to the file, also creates it if it doesn't exist
void addEntries() {
    string entry;
    cout << "Opening file..." << "\n";
    ofstream myFile("journal.txt", ios::app);

    if (!myFile) {
        cerr << " -- Failed to open file -- " << endl;
        return;
    }
    else {

        cout << " -- File Opened -- \n\nADD ENTRY HERE\n";
        cout << "--------------\n\n"; 

        getline(cin, entry);

        myFile << "--------------------" << endl;
        myFile << "Entry Date: " << __DATE__ << " " << __TIME__ << endl;
        myFile << entry << endl;
        myFile << "---------------------------------" << endl;
        cout << "\n-- Entry Archived -- \n\n";
        myFile.close();

    }
    return;


}


void searchEntries() {
    string line;
    string search;
    
    ifstream inFile("journal.txt");
    if (!inFile) {
        cerr << " -- Unable to open file -- " << endl;
        return;
    }


    cout << "What would you like to search for? (type the sentence or words)";
    getline(cin, search);

    //Code here sourced from https://www.w3resource.com/cpp-exercises/file-handling/cpp-file-handling-exercise-11.php#h_one
    //I liked their way of searching for the line and adding it to a vector.
    //It enables a great way of accessing the lines.
    string border = "--------";
    vector<int> borders;
    vector<int> line_numbers;
    int linenumber = 0;

    while (getline(inFile, line)) {

        if (line.find(search) != string::npos) {
            line_numbers.push_back(linenumber);
        }
        linenumber++;
    }

    while (getline(inFile, line)) {
        if (line.find(border) != string::npos) {
            borders.push_back(linenumber);
        }
        linenumber++;
    }  
    //End of sourced code

    //I'd like to code this, but I'm not sure how to implement it
    /*
    if (beginning line < search && search < endline) {
        while (getline(inFile, line) && beginning < end) {
        cout << line << endl;
        linecount ++;

        }
    } 
    */    

    if (inFile.eof()) {
        cout << "\n\n-- End of File -- " << endl;
    } else {
        cout << " -- Error occurred while reading file -- " << endl;
    }

    inFile.close();
    return;

}


int displayMenu() {
    cout << "\n-------- PERSONAL JOURNAL SYSTEM --------\n";
    cout << "1. Add New Entry\n";
    cout << "2. View All Entries\n";
    cout << "3. Search Entries\n";
    cout << "4. Exit\n";
    cout << "Please enter your choice (1-4): ";

    return getIntInput();

}

int main() {

bool running = true;

    while (running == true) {
        int choice = displayMenu();

        switch (choice) {
         
            case 1: //Add entry
                addEntries();
                break;

            case 2: //View entries
                displayEntries();
                break;

            case 3: //Search
                searchEntries();
                break;


            case 4: //Exit
                cout << "\nExiting Journal System...\n";
                running = false;
                break;

                
            default: // Error/invalid input catch
                cout << "\nInvalid choice. Please enter another.\n";
        }
    } 


    return 0;
}