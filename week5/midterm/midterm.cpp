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
    while (lchoice == 1){
        taskList.push_back ({});

        cout << "What is the title of the task? ";
        getline(cin, taskList[count].title);
        
        cout << "\nWhat is the description of the task? ";
        getline(cin, taskList[count].description);

        cout << "\nWhat is the priority level? (1-10)";
        cin >> taskList[count].priority;

        cout << "\nWhat is the due date of the task? (type in order -> day, month, year): ";
        cin >> taskList[count].dueDate.day;
        cin >> taskList[count].dueDate.month;
        cin >> taskList[count].dueDate.year;

        cout << "\nIs this task completed? (0 for no/1 for yes): ";
        cin >> taskList[count].completed;

        
        cout << taskList[count].title << endl;
        cout << taskList[count].description << endl;
        cout << taskList[count].priority << endl;
        cout << taskList[count].dueDate.day << endl;
        cout << taskList[count].dueDate.month << endl;
        cout << taskList[count].dueDate.year << endl;
        cout << taskList[count].completed << endl;

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
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i].title << endl;
        cout << vec[i].description << endl;
        cout << vec[i].priority << endl;
        cout << vec[i].dueDate.day << endl;
        cout << vec[i].dueDate.month << endl;
        cout << vec[i].dueDate.year << endl;
        cout << vec[i].completed << endl;
    }
    printf(" ");
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
        printf("%-10p | %5p | %8p\n", tasks[i].title, tasks[i].dueDate.day, tasks[i].completed);
    }
    return;
}


//Main function handling all other function calls, and formating the displays
int main (){
    vector<Task> taskList;
    int choice;
    
    cout << " --- Welcome to the Task Manager system ---" << endl;
    cout << "Would you like to write or read taks data? (1 to write/0 to read)" << endl;
    cin >> choice;
    if (choice == 1) {
        cout << "-This program will continue until you stop it- \n - (Enter 0 to stop at prompt) - " << endl;
        cin.ignore();
        inputTasks(taskList); 
    }
    else if (choice == 0) {
        taskList.push_back(
            {   "Sample Title", 
                "Sample Description", 
                5,
                {24, 4, 2025},
                true
        });
        displayTasks(taskList);
    }
    else {
        cout << "Error in Input" << endl;
    }

    cout << " - What next? - " << endl;
    cout << "-(0 to read/1 to write/2 to exit)-" << endl;
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
        cout << "User exited program." << endl;
    }

    cin.ignore();
    char choicer;
    cout << "Would you like to sort tasks or generate a report? (s for sort | y for report | n for exit)" << endl;
    cin >> choicer;

    if (toupper(choicer) == 'S') {
        cout << "Sorted by priority:" << endl;
        sort(taskList.begin(), taskList.end(), taskByPriority);
        displayTasks(taskList);

        cout << "Sorted by date (day): " << endl;
        sort(taskList.begin(), taskList.end(), taskByDueDate);
        displayTasks(taskList);
    
        cout << "Sorted by completion status (completed first/incomplete last):" << endl;
        sort(taskList.begin(), taskList.end(), tasksByStatus);
        displayTasks(taskList);

    }

    else if (toupper(choicer) == 'Y') {
    cout << "Productivity Report: " << endl;
    productivityGenerator(taskList);
    }

    else {
        cout << "-- User exited program --" << endl;
    }

    return 0;

}


