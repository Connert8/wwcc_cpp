#include <iostream>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;


//Temperature calculating and outputting function
double temperatureCalcout(double temps[], char choice) {
    //Average Calculation
    int sum = 0;
    for (int i = 0; i < 7; i++) {
        sum += temps[i];
    }
    double average = sum / 7.0;

    // Highest and smallest calculations
   double largest = temps[0];
    double smallest = temps[0];
    for (int i = 1; i < 7; i++) {
        if (temps[i] > largest) {
            largest = temps[i];
           }
           if (temps[i] < smallest) {
            smallest = temps[i];
           }
    }

    //Output of high, low, and average temps
    cout << "Highest temperature: " << largest << choice << endl;
    cout << "Lowest temperature: " << smallest << choice << endl;
    cout << "Average temperature: " << setprecision(3) << average << choice << endl;

    //Above average temps
    cout << "Days with above-average temperatures: " << endl;
    
    //Checking to see which index has higher than previous average
    for (int i = 0; i < 7; i++) {
        if (temps[i] > average) {
            cout << "- Day " << i << ": " << temps[i] << choice << endl;
        }
        else {
            continue;
        }
    }

    return temps[7];
}

// Main function
int main() {

    //Initialization and asking for input
    char choice; 
    double temps[7];
    cout << "What unit of temperature would you like to enter? (K/C/F)" << endl;
    cin >> choice;
    cout << "Temperature Tracker\n ------------------------ " << endl;
    
    //Checks to see input is correct
    if (toupper(choice) == 'K' || toupper(choice) == 'C' || toupper(choice) == 'F' ) {
        //User enters each temp
        for (int i = 0; i < 7; i++) {
            cout << "Enter temperature for day " << (i + 1) << ": " << endl;
            cin >> temps[i];
        }
        //Calls the calculations and output function
        cout << "Temperature Analysis: " << endl;
        temperatureCalcout(temps, choice);

    }
    else {
        cout << " -- Error in input -- " << endl;
    }


    return 0;
}

