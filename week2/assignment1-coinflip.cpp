#include <iostream>
#include <cstdlib>  // For rand() function
#include <ctime>    // For time() function
using namespace std;

int main() {
    // Seed the random number generator
    srand(time(0));

    double flips = 0;
    double heads = 0;
    double tails = 0;

    cout << "Coin Flip Simulator" << endl;
    cout << "How many flips would you like to simulate? ";
    cin >> flips;

    // Your code here
    for (int i = 0; i < flips; i++) {
        int rando = rand() % 2;
        cout << rando << endl;
        if (rando == 1) {
            heads += 1;
        }
        else if (rando == 0) {
            tails += 1;
        }
        else {
            cout << "Error in loop" << endl;
        }
    }

    double htot = heads/flips;
    double ttot = tails/flips;

    cout << "Results: " << "\n";
    printf("%-5s | %5.0f | %5.2f\n", "Heads:", heads, htot);
    printf("%-5s | %5.0f | %5.2f\n", "Tails:", tails, ttot);


    return 0;
}
