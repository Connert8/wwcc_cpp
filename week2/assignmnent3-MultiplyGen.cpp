#include <iostream>
using namespace std;


int main() {
    
    int start, end;

    cout << "Multiplication Table Generator" << endl << endl;

    cout << "Enter starting number: ";
    cin >> start;

    cout << "Enter ending number: ";
    cin >> end;

    // Validating input
    if (start > end) {
        cout << "Error: Starting number must be less than ending number." << endl;
        return 0;
    }
    //Generating the Multiplication table
    else { 
        for (int i = start; i <= end; i++) {
            for (int j = start; j <= end; j++) {
                cout << " | " << i * j << " | "; 
            }
            cout << endl; 
        }
        cout << endl;
    }

    return 0;
}