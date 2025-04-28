#include <iostream>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;



// Function prototype
void convertTemperature(char &, double &);
//Make it take ckf

// Function definition
void convertTemperature(char &temunit, double &tempn) {

//Celcius Conversions
    if (toupper(temunit) == 'C') {
        if (tempn <= -273.15) {
            cout << "Invalid Temperature" << endl;
            return;
        }
        cout << "Celsius to Farenheit: "<< (tempn * (9/5)) + 32 << endl;
        cout << "Celsius to Kelvin: "<< tempn + 273 << endl;
    }

//Farenheit Conversions
    else if (toupper(temunit) == 'F') {
        if (tempn <= -469.67) {
            cout << "Invalid Temperature" << endl;
            return;
        }
        cout << "Farenheit to Celsius: "<< (tempn * (9/5)) - 32 << endl;
        cout << "Farenheit to Kelvin: "<< (tempn * (5/9)) + 273 << endl;
    }


//Kelvin Conversions
    else if (toupper(temunit) == 'K') {
        if (tempn < 0) {
            cout << "Invalid Temperature" << endl;
            return;
        }
        cout << "Kelvin to Celsius: "<< tempn - 273 << endl;     
        cout << "Kelvin to Farenheit: "<< (tempn * (9/5)) - 241 << endl;
    }

    else {
        cout << "Error in conversion" << endl;
    }

}

int main() {


    char temunit;
    double tempn;
    cout << "Enter the unit (C for Celsius, F for Fahrenheit, K for Kelvin): " << endl;
    cin >> temunit;
    cout << "Enter a temperature value: " << endl;
    cin >> tempn;



    cout << "Temperature Conversions: " << endl;
    convertTemperature(temunit, tempn);
    return 0;

}
