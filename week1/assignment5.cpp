#include <iostream>
using namespace std; 

int main() {
    short int loopnum;
    short int runs;
    cout << "Pick a number between 1 and 10" << endl;
    cin >> loopnum;

    for (int row = 1; row < loopnum + 1; ++row) {
        for (int col = 1; col <= row; ++col){
            cout << col << " ";
            runs += 1;
        }
        cout << "\n";
    } 

    return 0;
}