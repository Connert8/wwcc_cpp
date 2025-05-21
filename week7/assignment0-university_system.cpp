//For this program, I wanted to implement more systems and better user experience.
//I'll be using the Canvas pages for reference (will state above code used).
//In future programs, I'll be keeping longer operations in seperate functions for ease of reading.

#include <iostream>
#include <limits>
#include <vector>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;


//Student class
class Student {
private:
    string name;
    int id;
    double gpa;

public:
    Student();
    Student(string n, int d, double g) {
        name = n;
        id = d;
        gpa = g;
    }

    //Accessors
    string getStudentName() const { return name; }
    int getStudentId() const { return id; }
    double getStudentGpa() const {return gpa; }

    //Mutator
    void setStudentGpa(double newgpa) { gpa = newgpa; }
        

    //Get student method to print information
    void getStudent() const {
        cout << "ID: " << id << " - " << name << endl;
        cout << "GPA: " << gpa << "\n" << endl;
        
    }

};

//Courses class
class Course {
private:
    int code;
    string title;
    int credhrs;

public:
    Course();
    Course(int c, string t, int cred) {
        code = c;
        title = t;
        credhrs = cred;
    }

    //Accessors
    int getCourseCode() const { return code; }
    string getCourseTitle() const { return title; }
    int getCourseCreditHours() const {return credhrs; }

    //Getter for course info
    void getCourse() const {
        cout << code << ": " << title << " (" << credhrs << " credits)" << endl;
        
    }

};


//Sourced from Canvas page example
//Clears the input for user entry
void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

//Sourced from Canvas page example
//Here, the input is checked to make sure it's a valid integer input
//If not, it clears the input and keeps the program running.
//If it's a good input, it clears the input to make sure the next is good as well.
int getIntInput() {
    int value;
    while (!(cin >> value)) {
        cout << "Invalid input. Please enter a number: ";
        clearInputBuffer();
    }
    clearInputBuffer();
    return value;
}

//Same as last function, only it returns a double value instead of integer
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
    cout << "\n-------- UNIVERSITY MANAGEMENT SYSTEM --------\n";
    cout << "1. List all Students\n";
    cout << "2. List all Courses\n";
    cout << "3. Update a student's GPA\n";
    cout << "4. Exit\n";
    cout << "Please enter your choice (1-4): ";

    return getIntInput();

}


//Main function
int main() {
    Student s1("Gabe", 045, 4.0);
    Student s2("Gloria", 034, 3.895);
    Student s3("Gooby", 104, 2.1);

    Course c1(101, "English", 5);
    Course c2(223, "Calculus", 3);      

    bool running = true;

   
//While loop used in reference of Canvas pages (Class Based Projects and Encapsulation)
    while (running == true) {
        double gpa;
        int choice = displayMenu();
        int upd = 0;

        switch (choice) {
         
            case 1: // Get student information and display it
                cout << "\nStudent Information: \n";
                s1.getStudent();
                s2.getStudent();
                s3.getStudent();
                break;

            case 2: // Get course information and display
                cout << "\nCourse Information: \n";
                c1.getCourse();
                c2.getCourse();
                break;

            case 3: // Update GPA
                cout << "\n-- Updating GPA --\n";
                cout << "Which student would you like to update?" << endl;
                cout << "1. Gabe\n2. Gloria\n3. Gooby\nEnter (1-3): ";
                upd = getIntInput();
                //This set of ifs could be in a seperate function, although due to time it'll remain here
                if (upd == 1) {
                    cout << "Enter the new GPA: ";
                    gpa = getDoubleInput();
                    //Checks to see if gpa is out of valid range
                    if (gpa > 4.0 || gpa < 0.0) {
                        cout << " - Invalid GPA - " << endl;
                    }
                        else {                    
                        s1.setStudentGpa(gpa);
                        cout << "Updating Gabe's GPA to " << gpa << "...\n" << endl;
                        cout << "Updated student information: "<< endl; 
                        s1.getStudent(); 
                    }
                }
                else if (upd == 2) {
                    cout << "Enter the new GPA: ";
                    gpa = getDoubleInput();
                    if (gpa > 4.0 || gpa < 0.0) {
                        cout << " - Invalid GPA - " << endl;
                    }
                    else {
                        s2.setStudentGpa(gpa);
                        cout << "Updating Gloria's GPA to " << gpa << "..." << endl; 
                        cout << "Updated student information: " << endl;
                        s2.getStudent();     
                    }               
                }
                else if (upd == 3) {
                    cout << "Enter the new GPA: ";
                    gpa = getDoubleInput();
                    if (gpa > 4.0 || gpa < 0.0) {
                        cout << " - Invalid GPA - " << endl;
                    }
                    else {
                        s3.setStudentGpa(gpa);
                        cout << "Updating Gooby's GPA to " << gpa << "..." << endl; 
                        cout << "Updated student information: " << endl; 
                        s3.getStudent();  
                    }                 
                }
                else {
                    cout << " -- Error in updating -- ";
                    break;
                }

                break;


            case 4: // Exit case
                cout << "\nExiting University System...\n";
                running = false;
                break;

            default: // Error/invalid input catch
                cout << "\nInvalid choice. Please enter another.\n";
        }

    }

    return 0;


}
