#include <iostream>
#include <cmath>
using namespace std;

int main() {

    //Initializes coordinates
    float x1;
    float y1;
    float x2;
    float y2;

    //Asks and stores inputs
    cout << "What is your first coordinate?" << "\n" << "Type the x coordiante first, then the second." << endl;
    cin >> x1;
    cin >> y1;
    cout << "What is your second coordinate?" << "\n" << "Type the x coordiante first, then the second." << endl;
    cin >> x2;
    cin >> y2;

    // Calculates the distance
    float dista1 = x2 - x1;
    float dista2 = y2 - y1;
    float fdista = hypot(dista1, dista2);

    //Output
    printf("%-5s | %5.2f\n ", "x1: ", x1);
    printf("%-5s | %5.2f\n ", "y1: ", y1);
    printf("%-5s | %5.2f\n ", "x2: ", x2);
    printf("%-5s | %5.2f\n ", "y2: ", y2);
    cout << "The distance between " << "(" << x1 << ", " << y1 << ") "
    "and " << "(" << x2 << ", " << y2 << ") " << "is: ";
    printf("%0.2f\n", fdista);

    return 0;
}
