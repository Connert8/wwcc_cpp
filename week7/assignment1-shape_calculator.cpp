
#include <iostream>
#include <limits>
#include <vector>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;


//Rectanlge class
class Rectangle {
private:
    double length;
    double width;


public:
    Rectangle();
    //Constructor
    Rectangle(double l, double w) {
        length = l;
        width = w;

    }

    //Getters
    double getLength() const { return length; }
    double getWidth() const { return width; }

    //Setters
    void setLength(double newlength) { length = newlength; }
    void setWidth(double newwidth) { length = newwidth; }

    //Print rectangle info 
    void getRectangle() const {
        cout << "Rectangle (Length: " << length << ", Width: " << width << ")" << endl;
        cout << "Area: " << area();
    }


    //Calcuate area
    double area() const {
        return length * width;
    }


    Rectangle& area(double w, double l) { 
        //I'm not sure how to pass the area by reference and store here.

    }

    //Resizing rectangle
    Rectangle& resize(double mult) {
        length = length * mult;
        width = width * mult;
        return *this;
    }

};

//Circle class
class Circle {
private:
    double radius;

public:
    Circle();
    //Constructor
    Circle(double r) : radius(r) {}

    //Getter
    double getRadius() const { return radius; }

    //Printing formatted circle
    void print() const {
        double rad = getRadius();
        double circum = 2 * 3.14159 * rad;
        cout << "Circle (Radius: " << getRadius(); cout << ")" << endl;
        cout << "Area: " << rad * rad * 3.14159 << endl;
        cout << "Circumference: " << circum << endl;
    }

    //Printing detailed information on circle
    bool print(bool toprint) const {
        if (toprint == true) {
            double rad = getRadius();
            double circum = 2 * 3.14159 * rad;
            cout << "Circle Details: " << endl;
            cout << "Radius: " << getRadius() << endl;
            cout << "Area: pi x radius^2 = 3.14159 x " << rad * rad << " = " << rad * rad * 3.14159 << endl;
            cout << "Circumference: 2 x pi x " << rad << " = 2 x 3.14159 x " << rad << " = " << circum << endl;
            return false;
        }
        else {
            return false;
        }

    }


};


void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}


int getIntInput() {
    int value;
    while (!(cin >> value)) {
        cout << "Invalid input. Please enter a number: ";
        clearInputBuffer();
    }
    clearInputBuffer();
    return value;
}

double getDoubleInput() {
    double value;
    while (!(cin >> value)) {
        cout << "Invalid input. Please enter a decimal: ";
        clearInputBuffer();
    }
    clearInputBuffer();
    return value;
}




//Displays the menu for the user
int displayMenu() {
    cout << "\n-------- SHAPE CALCULATOR --------\n";
    cout << "1. List Rectangle Data\n";
    cout << "2. List Circle Data\n";
    cout << "3. Resize the Rectangle\n";
    cout << "4. Exit\n";
    cout << "Please enter your choice (1-4): ";

    return getIntInput();

}


//Main function
int main() {
    Rectangle r1(4.0, 2.0);
    Circle c1(5.0);
    bool running = true;

   //Menu operation for user, while running, ask for the input
    while (running == true) {
        bool toprint = false;
        int choice = displayMenu();
        int choice2 = 0;
        double factor = 1;

        switch (choice) {
         
            case 1: //Get's rectangle info
                r1.getRectangle();
                break;

            case 2: // Gets circle info and asks for detailed info
                cout << "Would you like all circle details, or simple data? (0 for simple/1 for all)";
                choice2 = getIntInput();
                if (choice2 == 0) {
                    c1.print();
                    break;                    
                }
                else if (choice2 == 1) {
                    toprint = true;
                    c1.print(toprint);
                    break;
                }
                else {
                    cout << " -- Error in input -- " << endl;
                    break;
                }

            case 3: //Resizes rectangle based on user input
                cout << "By what factor do you wish to resize the rectangle?";
                factor = getDoubleInput();
                r1.resize(factor);
                r1.getRectangle();
                break;


            case 4: //Exits systems
                cout << "\nExiting System...\n";
                running = false;
                break;

            default: // Error/invalid input catch
                cout << "\nInvalid choice. Please enter another.\n";
        }

    }

    return 0;


}