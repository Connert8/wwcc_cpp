//I wanted to make all the functions in the main into their own seperate functions,
//due to time they'll have to be somewhat messy.
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

//Student struct with average calculating function
struct Student {
    string id;
    string firstName;
    string lastName;
    vector<int> courses;
    vector<double> gpa;
    double average;

    double calculateAverage() {
        if (gpa.empty()) return 0.0;
        double sum = 0;
        for (int score : gpa) {
            sum += score;
        }
        average = sum / gpa.size();
        return average;
    }
};

//Main function
int main() {

    cout << "STUDENT ACADEMIC RECORD PROCESSOR\n";
    cout << "---------------------------------\n";


    //Opening to read file
    ifstream inputFile("grades.txt");
    if (!inputFile) {
        cerr << "Error: Cannot open grades.txt" << endl;
        return 1;
    }

    vector<Student> students;

    string line;
    int lineNumber = 0;
    int errorCount = 0;

    // Process file 
    while (getline(inputFile, line)) {
        lineNumber++;

        // Skip empty lines and comments
        if (line.empty() || line[0] == '#') {
            continue;
        }

        stringstream ss(line);
        Student student;

        // Ensure correct format
        if (!(ss >> student.id >> student.firstName >> student.lastName)) {
            cerr << "Warning: Invalid format at line " << lineNumber << endl;
            errorCount++;
            continue;
        }


        //Getting courses and gpa for student vector
        int course;
        double score;
        int i = 0;
        while (ss >> course >> score) {
            if (score < 0.0 || score > 4.0) {
                cerr << "Warning: Invalid GPA " << score << " at line " << lineNumber << endl;
                errorCount++;
            } else {
                student.courses.push_back(course);
                student.gpa.push_back(score);
            }
            i++;
        }


        // Only add students with valid data
        if (!student.gpa.empty()) {
            student.calculateAverage();
            students.push_back(student);
        }
    }

    inputFile.close();



    // Generate report
    cout << "\nCLASS STATISTICS" << endl;
    cout << "-----------------\n";
    cout << "Total Students: " << students.size() << endl;
    cout << "Errors encountered: " << errorCount << endl;
    
    //Goes through data and finds the highest and lowest gpas
    double highest = 0.5;
    double lowest = 3.99;
    double ave = 0.0;
    for (const auto& s : students) {
        if (s.gpa[0] > highest) {
            highest = s.gpa[0];
        }
        else if (s.gpa[0] < lowest) {
            lowest = s.gpa[0];
        }
        else {
            continue;
        }
        ave = s.average; 
    }

    //Gets total courses
    int totalcourses = 0;
    for (const auto& s : students) {
        totalcourses += s.courses[0];
    }

    cout << "Highest GPA: " << highest << "\n";
    cout << "Lowest GPA: " << lowest << "\n";
    cout << "Class Average GPA: " << ave << "\n";
    cout << "Total Classes Taken: " << totalcourses << "\n\n";
    
    
    // Display student data
    cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(15) << "Courses Taken" << "  GPA" << endl;
    cout << string(50, '-') << endl;


    for (const auto& s : students) {
        cout << left << setw(10) << s.id;
        cout << setw(20) << (s.firstName + " " + s.lastName);
        cout << setw(15) << s.courses[0];
        cout << "  " << fixed << setprecision(2) << s.gpa[0] << endl;
    }


    //Write all data onto new report file
    cout << "Generating Report..." << "\n";
    ofstream myFile("gradesreport.txt", ios::app);

    if (!myFile) {
        cerr << " -- Failed to create file -- " << endl;
    }
    else {
    
        myFile << "Highest GPA: " << highest << "\n";
        myFile << "Lowest GPA: " << lowest << "\n";
        myFile << "Class Average GPA: " << ave << "\n";
        myFile << "Total Classes Taken: " << totalcourses << "\n\n";
        
        
        // Display student data
        myFile << left << setw(10) << "ID" << setw(20) << "Name" << setw(15) << "Courses Taken" << "  GPA" << endl;
        myFile << string(50, '-') << endl;


        for (const auto& s : students) {
            myFile << left << setw(10) << s.id;
            myFile << setw(20) << (s.firstName + " " + s.lastName);
            myFile << setw(15) << s.courses[0];
            myFile << "  " << fixed << setprecision(2) << s.gpa[0] << endl;
        }

        myFile.close();
    }

    return 0;
}