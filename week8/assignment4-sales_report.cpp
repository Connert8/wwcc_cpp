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

//Sale data struct with vectors for numbered items
struct SaleData {
    string date;
    string productname;
    string category;
    vector<int> quantity;
    vector<double> unitprice;


};

//Diplays report in sales.txt for console view
void displayReport() {
    ifstream inFile("sales.txt");
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

//Calculates revenue
double calculateTotalRevenue(vector<SaleData>& sales) {

    vector<double> itemrev;
    double totalrev;

    //Adds the revenue of each item into one vector
    for (const auto& s : sales) {
        itemrev.push_back(s.quantity[0] * s.unitprice[0]);
    }

    //totals all items into one total
    for (size_t i = 0; i < itemrev.size(); i++) {
        totalrev += itemrev.at(i);
    }

    return totalrev;

}

//Counts the quantity for every product
int totalUnitsSold(vector<SaleData>& sales) {
    int totalunits = 0;
    double averagesaleval = 0.0;

    for (const auto& s : sales) {
        totalunits += s.quantity[0];
    }
    return totalunits;

}

//Counts all products by adding each place in struct
int totalProductsSold(vector<SaleData>& sales) {
    int totalproducts = 0;

    for (const auto& s : sales) {
        totalproducts += 1;
    }

    return totalproducts;
}

//Adds all quantities and calls revenue to divide, finding average sales
double averageSaleValue(vector<SaleData>& sales) {
    int sum = 0;
    double averagesaleval = 0.0;

    for (const auto& s : sales) {
        sum += s.quantity[0];

    }

    double rev = calculateTotalRevenue(sales);
    averagesaleval = rev/sum;
    return averagesaleval;

}


//Writes formatted report to file 
void writeReport(vector<SaleData>& sales) {
    //Change ios::out to ios::app if needing a lasting file
    ofstream myFile("sales_summary.txt", ios::out);

    if (!myFile) {
        cerr << " -- Failed to open file -- " << endl;
        return;
    }
    else {

        myFile << "SALES SUMMARY REPORT" << "\n";
        myFile << "Generated: ";

        //https://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c
        //Sourced from open stax,
        //I couldn't figure out how to get the time and date formatted on my own.
        std::time_t t = std::time(0);  
        std::tm* now = std::localtime(&t);
        myFile << (now->tm_year + 1900) << '-' 
                << (now->tm_mon + 1) << '-'
                <<  now->tm_mday;

        myFile << "  " << __TIME__;
        myFile << "\n=========================================\n\n";
        
        //Format for heading labels
        myFile << left << setw(25) << "Product" 
            << setw(15) << "Category" << right
            << setw(15) << "Units Sold"
            << setw(15) << "Unit Price" 
            << setw(15) << "Total Revenue" << endl;

        //Format for actual data
        for (const auto& s : sales) {
            myFile << left << setw(25) << s.productname 
                << setw(15) << s.category << right
                << setw(15) << s.quantity[0] 
                << setw(15) << s.unitprice[0]
                << setw(15) << s.quantity[0] * s.unitprice[0] << endl;
        }
        myFile << "\n\n";

        //Summary format
        myFile << "=====================================" << endl;
        myFile << "SUMMARY STATISTICS" << endl;
        myFile << "=====================================" << endl;

        //Calls the previous functions for statistic output
        myFile << "Total Products Sold: " << totalProductsSold(sales) << endl;
        myFile << "Total Units Sold: " << totalUnitsSold(sales) << endl;
        myFile << "Total Revenue: $" << fixed << setprecision(2) << calculateTotalRevenue(sales) << endl;
        myFile << "Average Sale Value: $" << fixed << setprecision(2) << averageSaleValue(sales) << endl;

        myFile.close();
    }
    return;

}



int main() {
        
    //Opening sales file to parse data
    ifstream inputFile("sales.txt");
    if (!inputFile) {
        cerr << "Error: Cannot open sales.txt" << endl;
        return 1;
    }

    vector<SaleData> sales;

    string line;
    int lineNumber = 0;
    int errorCount = 0;

    while (getline(inputFile, line)) {
        lineNumber++;

        // Skip empty lines and comments
        if (line.empty() || line[0] == '#') {
            continue;
        }

        stringstream ss(line);
        SaleData sale;

        // Ensure correct format
        if (!(ss >> sale.productname >> sale.category)) {
            cerr << "Warning: Invalid format at line " << lineNumber << endl;
            errorCount++;
            continue;
        }


        //Getting quantities and prices for sale vector
        int amount;
        double pricing;
        while (ss >> amount >> pricing) {
            if (pricing < 0.0 || amount < 0) {
                cerr << "Warning: Invalid Price/Quantity at line " << lineNumber << endl;
                errorCount++;
            } else {
                sale.quantity.push_back(amount);
                sale.unitprice.push_back(pricing);
            }
        }


        // Only add sales with valid data
        if (!sale.unitprice.empty()) {
            sales.push_back(sale);
        }
    }


    inputFile.close();

    //displays to console
    displayReport();
    //writes to seperate file
    writeReport(sales);


    return 0;
}

