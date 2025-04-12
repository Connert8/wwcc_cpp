#include <iostream>
using namespace std; 

int main() {
    char temunit;
    double tempn;
    short int ckof;
    cout << "What is the unit of tempurature? (Type C, F, or K)" << endl;
    cin >> temunit;
    cout << "What is the temperature number?" << endl;
    cin >> tempn;
    cout << "What would you like to convert to?" << endl;
    cout << "Celcius? (Type 0)" << endl;
    cout << "Farenheit? (Type 1)" << endl;
    cout << "Kelvin? (Type 2)" << endl;
    cin >> ckof;

//Celcius Conversions
    if (temunit == 'C') {
        if (ckof == 0) { 
            cout << "Celsius to Celsius: " << tempn << endl;      
        }
        else if (ckof == 1) { 
            tempn = ((tempn * 9/5) + 32);
            cout << "Celsius to Farenheit: " << tempn << endl;      
        
        }
        else if (ckof == 2) { 
            tempn = tempn + 273;
            cout << "Celsius to Kelvin: " << tempn << endl;      
        
        }
    }

//Farenheit Conversions
    if (temunit == 'F') {
        if (ckof == 0) { 
            tempn = (tempn - 32 * 5/9);
            cout << "Farenheit to Celsius: " << tempn << endl;      
        }
        else if (ckof == 1) { 
            cout << "Farenheit to Farenheit: " << tempn << endl;      
        
        }
        else if (ckof == 2) { 
            tempn = (((tempn * (9/5) + 32)) + 273);
            cout << "Farenheit to Kelvin: " << tempn << endl;      
        
        }
    }


//Kelvin Conversions
    if (temunit == 'K') {
        if (ckof == 0) { 
            tempn = tempn - 273;
            cout << "Kelvin to Celsius: " << tempn << endl;      
        }
        else if (ckof == 1) { 
            tempn = (((tempn - 273) * (9/5) + 32));
            cout << "Kelvin to Farenheit: " << tempn << endl;      
        
        }
        else if (ckof == 2) { 
            cout << "Kelvin to Kelvin: " << tempn << endl;      
        
        }
    }

    return 0;
}