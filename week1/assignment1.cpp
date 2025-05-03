#include <iostream>
using namespace std; 
#include <string>

int main() {
    string x;
    string y;
    cout << "What is your name?" << endl;
    cin >> x;
    cout << "What is your credit card pin number?" << endl;
    cin >> y;
    cout << "You really typed in your pin?" << "(" << y << ")";

    return 0;
}
