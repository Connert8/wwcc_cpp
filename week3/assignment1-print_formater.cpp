#include <iostream>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;


//Number (integer) formating
int format(int numb) {
    //Converts to string and looks for which parts of the number need a comma
    std::string formnumb = to_string(numb);
    for (int i = formnumb.length(); i > 1; i--) {
        cout << i << endl;
        if (formnumb.length()%3 == 0){
            if (i%3 == 0 && i != formnumb.length()) {
                formnumb.insert(i, ",");
            }
            else {
                continue;
            }
        }

        else if (formnumb.length()%2 == 0 || formnumb.length()%5 == 0) {
            if (i%3 == 0 && i != formnumb.length()) {
                formnumb.insert(i-1, ",");
            }
            else {
                continue;
            } 
        }

        else {
            continue;
        }
    }

    cout << formnumb << endl;
    return 0;
}


//Decimal number formating
double format(double dnumb) {
    //Convert to string and find where the . is to erase everything after
    std::string dform = to_string(dnumb);
    for (int i = 0; i < dform.length(); i++){
        if (dform[i] == '.') {
            dform.erase(i+3);
        }
        else {
            continue;
        }
    }
    cout << dform << endl;
    return 0;

}


//Formating the words
string format(string word) {
    //Makes the first character and each after a space into uppercase
    bool makeUpper = true;
    for (char &c : word) {
        if (makeUpper && isalpha(c)) {
            c = toupper(c);
            makeUpper = false;
        } 
        else if (c == ' ') {
            makeUpper = true;
        }
    }
    return word;
}


// Main function
int main() {
    //Initial request for numbers or words
    string word;
    int quest;
    cout << "Would you like to enter a number or word/sentence?" << endl << "(1 for numbers, 0 for words)" << endl;
    cin >> quest;

    //Initiates words
    if (quest == 0) {
        string word;
        cin.ignore();
        cout << "Enter a word or sentence: ";
        getline(cin, word);
        cout << "Original: " << word << endl;
        cout << "Formatted: " << format(word) << endl;
    }

    //Initiates numbers
    else if (quest == 1){
        int choice1;
        double dnumb;
        int numb;
        cin.ignore();
        cout << "Would you like to enter a decimal or integer? (0 = integer/1 = decimal)"; 
        cin >> choice1;

        //Checks for integer or decimal
        if (choice1 == 0){
            cout << "Enter a number: ";
            cin >> numb;
            if (numb < 0) {
                cout << "Error in Input" << endl;
            }
            else {
                cout << "Original number: " << numb << endl;
                cout << "Formatted: " << format(numb) << endl;
            }
        }

        else if (choice1 == 1) {
            cout << "Enter a decimal: ";
            cin >> dnumb;
            if (numb < 0) {
                cout << "Error in Input" << endl;
            }
            else {
                cout << "Original number: " << dnumb << endl;
                cout << "Formatted: " << format(dnumb) << endl;
            }
        }
        
        else {
            cout << "Error in Input" << endl;
        }
    }

    //Error catch
    else {
        cout << " -- Error, input unrecognized -- " << endl;
    }

    return 0;
}

