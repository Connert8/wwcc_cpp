#include <iostream>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;


//Sales calculating and output function 
//NOTE: I'll be working on making all of these operations
//into seperate functions in preparation for the midterm and other assignments
double salesCalcout(double sales[], string days[]) {
    //Average and sum calculation
    int sum = 0;
    for (int i = 0; i < 7; i++) {
        sum += sales[i];
    }
    double average = sum / 7.0;

    //Largest and smallest calculations
    double largest = sales[0];
    double smallest = sales[0];
    for (int i = 1; i < 7; i++) {
        if (sales[i] > largest) {
            largest = sales[i];
           }
           if (sales[i] < smallest) {
            smallest = sales[i];
           }
    }

    //sales summary start
    cout << "Sales Summary: " << endl;
    cout << "Total Sales: $" << sum << endl;
    cout << "Average Daily Sales: $" << fixed << setprecision(2) << average << endl;

    cout << endl;

    //Best day and worst day output
    //Looks for where the largest and smallest values are and makes the days match
    for (int i = 0; i < 7; i++) {
        if (sales[i] == largest) {
            cout << "Best Day: " << days[i] << " " << "with $" << largest << endl;
        }
        else if (sales[i] == smallest){
            cout << "Worst Day: " << days[i] << " " << "with $" << smallest << endl;
        }
        else {
            continue;
        }
    }

    cout << endl;

    //Above average sales
    cout << "Days with above-average sales: ";
    int aboveAve = 0;
    
    //Checking to see which index has higher than previous average
    for (int i = 0; i < 7; i++) {
        if (sales[i] > average) {
            aboveAve += 1;
        }
        else {
            continue;
        }
    }

    cout << aboveAve << endl;


    //Grabs the weekend values and calculates the percent of sales
    double endSales = sales[5] + sales[6];
    cout << "Weekend sales: $" << fixed << setprecision(2) <<
    endSales << " (" << (endSales/sum) * 100 << "% of total)" << endl;

    return sales[7];
}

// Main function
int main() {

    //Initializing arrays and output
    double sales[7];
    string days[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", 
        "Friday", "Saturday", "Sunday"};

    cout << " - Weekly Sales Analysis - \n ------------------------ " << endl;
    
        //User inputs sales and sets precision to 2 decimal places
        for (int i = 0; i < 7; i++) {
            cout << "Enter sales for  " << days[i] << ": ";
            cin >> fixed >> setprecision(2) >> sales[i];
            cout << endl;
        }
        //Calls the calculations and output function
        salesCalcout(sales, days);

    return 0;
}

