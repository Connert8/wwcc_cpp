//Midterm for C++ 
//Task Manager System
//This program can,
/* 
-Add tasks with title, description, priority, and due date
-Mark tasks as complete/incomplete
-Display tasks sorted by priority or due date
-Filter tasks by status (pending/completed)
-Generate productivity reports (tasks completed per week)
*/

#include <iostream>
#include <vector>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;


//Struct Initiation
struct Date {
    int day;
    int month;
    int year;
};

struct Task {
    string title;
    string description;
    int priority; //level 1-10
    Date dueDate;
    bool completed;
};


//Input tasks to list function
void inputTasks(vector<Task> &taskList) {
    int lchoice = 1;
    int count = 0;
    string temp;
    //While user wants to add tasks, continue prompting
    //Goes through every element in the Task struct
    while (lchoice == 1){
        taskList.push_back ({});

        cout << "What is the title of the task? ";
        getline(cin, taskList[count].title);
        
        cout << "\nWhat is the description of the task? ";
        getline(cin, taskList[count].description);

        cout << "\nWhat is the priority level? (1-10)";
        cin >> taskList[count].priority;

        cout << "\nWhat is the due date of the task? (day): ";
        cin >> taskList[count].dueDate.day;
        cout << "\n(Month)";
        cin >> taskList[count].dueDate.month;
        cout << "\n(Year)";
        cin >> taskList[count].dueDate.year;

        cout << "\nIs this task completed? (0 for no/1 for yes): ";
        cin >> taskList[count].completed;

        
        cout << " -- Task Entered -- " << endl;

        count += 1;
        cout << "\nWould you like to input another task? (0 to stop/1 to continue)" << endl;
        cin.ignore();
        cin >> lchoice;

    } 

    return;
    
}

//Sample list for display
void sampleTaskList(vector<Task> &taskList){

    taskList.push_back(
        {   "Sample 1", 
            "Description 1", 
            6,
            {21, 4, 2025},
            true
    });
    taskList.push_back(
        {   "Sample 2", 
            "Description 2", 
            2,
            {12, 5, 2025},
            false
    });

    return;

}

//Display function for all tasks
void displayTasks(vector<Task> vec){
    cout << "=====---------------=====" << endl;
    for (int i = 0; i < vec.size(); i++) {
        cout << "Title: " << vec[i].title << endl;
        cout << "Description: " << vec[i].description << endl;
        cout << "Priority Level (1-10): " << vec[i].priority << endl;
        cout << "Date (day/month/year): ";
        cout << "(" << vec[i].dueDate.day << "/"
        << vec[i].dueDate.month << "/"
        << vec[i].dueDate.year << ")" << endl;
    
        if (vec[i].completed == 1) {
            cout << "Complete" << endl;
        } 
        else if (vec[i].completed == 0) {
            cout << "Incomplete" << endl;
        }

        cout << "=====---------------=====" << endl;
    }

    return;
}

//Sourced From Canvas Page (Structs in depth)
//Sorts task by priority from high to low
bool taskByPriority(const Task &a, const Task &b) {
    return a.priority > b.priority;
}


//Sorts tasks by date day from low to high
bool taskByDueDate(const Task &c, const Task &d) { 
    return c.dueDate.day < d.dueDate.day;
}


/*
void markComplete() {

    In the future, I'd like to make this part carry over.
    Each time the code is run it would store in a seperate file.

}
*/

//Sorts tasks by status, complete first
bool tasksByStatus(const Task &e, const Task &f) { 
    return e.completed > f.completed;
}


//Generates report of the title, when it's due, and completion
void productivityGenerator(vector<Task> tasks) {
    printf("%-10s | %5s | %8s\n", "Task Title", "Due Date", "Completed (1 is yes/0 is no)");
    for (int i = 0; i < tasks.size(); i++) {
        //I'm unable to get the first pointer to return the correct title string
        printf("%-10p | %5p | %8p\n", tasks[i].title, tasks[i].dueDate.day, tasks[i].completed);
    }
    return;
}


//Main function handling all other function calls, and formating the displays
int main (){
    vector<Task> taskList;
    int choice;

    //Beginning of program, first prompt of read or write
    cout << " --- Welcome to the Task Manager system ---" << endl;
    cout << "Would you like to write or read task data? (type -1- to write or -0- to read)" << endl;
    cin >> choice;
    if (choice == 1) {
        cout << "-This program will continue until you stop it- \n - (Enter 0 to stop at prompt) - " << endl;
        cin.ignore();
        inputTasks(taskList); 
    }
    else if (choice == 0) {
        sampleTaskList(taskList);
        displayTasks(taskList);
    }
    else {
        cout << "Error in Input" << endl;
    }

    //Next, read/write/continue
    cout << " - What next? - " << endl;
    cout << "-(1 to write/0 to read/2 to continue)-" << endl;
    cin >> choice;

    if (choice == 1) {
        cout << "-This program will continue until you stop it-" << endl;
        cin.ignore();
        inputTasks(taskList); 
    }
    else if (choice == 0) {
        displayTasks(taskList);
    }
    else {
        cout << endl;
    }

    cin.ignore();
    char choicer;

    //Asking for the final action, sort/report/exit
    cout << "Would you like to sort tasks or generate a report? (s for sort | y for report | n for exit)" << endl;
    cin >> choicer;

    if (toupper(choicer) == 'S') {
        cout << "Sorted by priority:" << endl;
        sort(taskList.begin(), taskList.end(), taskByPriority);
        displayTasks(taskList);

        cout << "--------------------------------" << endl;

        cout << "Sorted by date (day): " << endl;
        sort(taskList.begin(), taskList.end(), taskByDueDate);
        displayTasks(taskList);

        cout << "--------------------------------" << endl;
    
        cout << "Sorted by completion status (completed first/incomplete last):" << endl;
        sort(taskList.begin(), taskList.end(), tasksByStatus);
        displayTasks(taskList);

        cout << "--------------------------------" << endl;


        cout << "End of Program" << endl;

    }

    else if (toupper(choicer) == 'Y') {
    cout << "Productivity Report: " << endl;
    productivityGenerator(taskList);

    cout << "End of Program" << endl;
    }

    else {
        cout << "-- User exited program --" << endl;
        cout << "-- End of Program --" << endl;
    }

    return 0;

}


/*
In the future, I'd like to add a better user interface.
*/

