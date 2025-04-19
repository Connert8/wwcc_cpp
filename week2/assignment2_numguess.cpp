#include <iostream>
#include <cstdlib>  // For rand() function
#include <ctime>    // For time() function
using namespace std;

int main() {
    // Seed the random number generator
    srand(time(0));

    // Generate random number between 1 and 100
    int secretNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;

    cout << "Number Guessing Game" << endl;
    cout << "I'm thinking of a number between 1 and 100." << endl << endl;
    cout << "Type a number to play!" << endl;
    cin >> guess;
    
    // Your code here
    
    if ((guess > 0) && (guess < 100)) {
        cout << "What is your first guess?" << endl;
        while (guess != secretNumber) {
            attempts += 1;
            cin >> guess;
            if (!cin) {
                cout << "Wrong input type" << endl;
                break;
            }
            else if (guess > secretNumber) {
                cout << "Too High" << endl;
                cout << "Try Again" << endl;
            }
            else if (guess < secretNumber) {
                cout << "Too Low" << endl;
                cout << "Try Again" << endl;
            }
            else if (guess = secretNumber) {
                break;
            }
            else {
                cout << "Error in loop.";
                break; 
            }

        }
    }
    else {
        cout << "Unrecoginzed input" << endl;
    }    
    if (!cin) {
        cout << "End of game." << endl;
        cout << "Number of tries: " << attempts << endl;
    
    }
    else if (guess = secretNumber){
        cout << "You guessed it correctly!" << endl;
        cout << "Number of tries: " << attempts << endl;
    
    }
    else {
        cout << "Game error." << endl;
    }

    return 0;
}