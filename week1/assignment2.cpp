#include <iostream>
using namespace std; 

int main() {
    int num1;
    int num2;
    cout << "What is your first number?" << endl;
    cin >> num1;
    cout << "What is your second number" << endl;
    cin >> num2;
    
    if (num2 == 0) { 
        cout << "Quotient error, unable to divide by 0" << endl;      
    
    }
    else {
        double add = num1 + num2;
        double sub = num1 - num2;
        double mul = num1 * num2;
        double div = num1 / num2;
        cout << "Sum: " << add << endl;
        cout << "Difference: " << sub << endl;
        cout << "Product: " << mul << endl; 
        cout << "Quotient: " << div << endl;
    }

    return 0;
}