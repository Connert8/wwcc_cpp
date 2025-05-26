//There were no #include statments, added them here.
#include <iostream>
#include <limits>
#include <vector>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;



// The class should have been capitalized
class Account {
    //The private data wasn't marked under private:
private:
    string customerName;
    double money;
    bool open;
    int acc_number;
    //Added more descriptive name
    string acc_type;
public:
//Constructor added. Before, it was a standard function which is improper.
    Account();
    Account(string n, int num, string t) {
        customerName = n;
        money = 0;
        open = true;
        acc_number = num;
        acc_type = t;
    }

    void deposit(double x) {
        money = money + x;
    }

    void withdraw(double x) {
        //Added validation that funds are available to withdraw.
        if (money - x < 0) {
            cout << " -- Error: funds are unavailable -- " << endl;
            return;
        }
        else {
            money = money - x;
        }
    }

    //Renamed per conventions and readability
    void calculateInterest()  {
        if (acc_type == "savings") {
            money = money * 1.03;
        } else if (acc_type == "checking") {
            money = money * 1.01;
        } else if (acc_type == "business") {
            money = money * 1.005;
        }
    }

    //Made sure const was present
    void print() const {
        cout << "Account Number: " << acc_number << endl;
        cout << "Customer Name: " << customerName << endl;
        cout << "Balance: $" << money << endl;
        cout << "Account Type: " << acc_type << endl;
        cout << "Status: " << (open ? "Open" : "Closed") << endl;
    }

    //Renamed per conventions
    void closeAccount() {
        open = false;
    }

    //Renamed per conventions
    //Added const per conventions
    double getMoneyAmount() const {
        return money;
    }
};

int main() {
    // Creating account now refers to constructor instead of assigning to function
    Account acc1("John Smith", 12345, "savings");

    // Perform operations
    acc1.deposit(1000);
    acc1.withdraw(250);
    acc1.calculateInterest();


    // Display information
    acc1.print();


    // Close the account
    acc1.closeAccount();

    return 0;
}