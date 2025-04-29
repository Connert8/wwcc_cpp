#include <iostream>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;



// Function prototypes
double dollartoEuro(double &);
double dollartoPound(double &);
double dollartoYen(double &);
int getConversionCount(int &);


//Counting Function
int getConversionCount(int &numofconvs) {
    numofconvs += 1;
    return numofconvs;
}

//Euro Conversions
double dollartoEuro(double &amount) {
    amount = amount * 0.85;
    return amount;
}

//Pound Conversions
double dollartoPound(double &amount) {
    amount = amount * 0.74;
    return amount;
}


//Yen Conversions
double dollartoYen(double &amount) {
    amount = amount * 110.33;
    return amount;

}

// Main function
int main() {
    // Initializing and starting program
    int numofconvs = 0;
    int choice;
    double amount;
    char quest;
    cout << "Would you like to perform a conversion? (y/n): " << endl;
    cin >> quest;

    //While the user wants to continue, will run here
    while (toupper(quest) == 'Y') {
        double amount = 0;
        //Table format for choosing conversion or exit
        cout << "Currency Converter " << endl << "---------------"  << endl;
        cout << "1. Convert USD to Euro (EUR)" << endl;
        cout << "2. Convert USD to British Pound (GBP)" << endl;
        cout << "3. Convert USD to Japanese Yen (JPY)" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        //Asking user for which conversion unit
        if (choice == 1) {
            cout << "Enter amount in USD: " << endl;
            cin >> amount;
            cout << amount << " USD = " << dollartoEuro(amount) << " EUR" << endl;         
        }
        else if (choice == 2) {
            cout << "Enter amount in USD: ";
            cin >> amount;
            cout << amount << " USD = " << dollartoPound(amount) << " GBP" << endl;         
        }
        else if (choice == 3) {
            cout << "Enter amount in USD: ";
            cin >> amount;
            cout << amount << " USD = " << dollartoYen(amount) << " JPY" << endl;         
        }
        else if (choice == 4) {
            cout << "Exiting Program..." << endl;
            break;         
        }
        else {
            cout << "Error in input" << endl;
            break;
        }

        //End of conversion display and recursion question
        cout << "Number of conversions performed: " << getConversionCount(numofconvs) << endl;
        cout << "Would you like to perform another conversion? (y/n): " << endl;
        cin >> quest;

    }

    //If the user exits
    if (toupper(quest) != 'Y') {
        cout << " -- Program exited -- " << endl;
        cout << "Number of conversions performed: " << numofconvs << endl;
    }

    return 0;

}
