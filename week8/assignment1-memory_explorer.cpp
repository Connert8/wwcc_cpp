#include <iostream>
#include <limits>
#include <vector>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;


//Here the values are passed by reference as indicated by the &
void referenceDemo(int& a, int& b) {
    a = a*10;
    b = b*10;
}

//Here, the values are pointed to and modified
void pointerDemo(int* x, int* y){
    *x = *x * 10;
    *y = *y * 10;

    
}


int main() {
    cout << "MEMORY ADDRESS EXPLORER" << "\n";
    cout << "-----------------------" << "\n";

    //Part 1
    //The variables are created and the next ones are pointers to the originals
    //The pointers are used to see the memory address
    cout << "\nPART 1: Variable Memory Locations" << "\n";
    cout << "----------------------------------" << "\n";
    int int_var = 42;
    int* ptr_int_var = &int_var;
    if (ptr_int_var != nullptr) {
    cout << "Integer variable: " << int_var << " at address " << ptr_int_var << "\n";
    }

    double double_var = 3.14;
    double* ptr_double_var = &double_var;
    if (ptr_double_var != nullptr) {
    cout << "Double variable: " << double_var << " at address " << ptr_double_var << "\n";
    }
    
    
    char char_var = 'A';
    char* ptr_char_var = &char_var;
    if (ptr_char_var != nullptr) {
    cout << "Character variable: " << char_var << " at address " << &ptr_char_var << "\n";
    }
    
    //part 2  
    //The values are taken and passed to the reference function
    cout << "\nPART 2: Reference Demonstration" << "\n";
    cout << "-------------------------------" << "\n";
    int c = 10;
    int d = 20;
    cout << "Before reference function: x = "<< c << ", y = " << d << "\n";
    referenceDemo(c, d);
    cout << "After reference function: x = " << c << ", y = " << d << "\n";


    //part 3 
    //The values are taken and passed to the pointer function

    cout << "\nPART 3: Pointer Demonstration" << "\n";
    cout << "-----------------------------" << "\n";
    int beforex = 5;
    int beforey = 15;
    cout << "Before pointer function: a = "<< beforex << ", b = " << beforey << "\n";
    pointerDemo(&beforex, &beforey);
    cout << "After pointer function: a = " << beforex << ", b = " << beforey << "\n";



    //part 4
    //Array is created and a pointer is also created. The output is the address of the pointer and the arithmatic.
    cout << "\nPART 4: Array and Pointer Relationship" << "\n";
    cout << "--------------------------------------" << "\n";
    int array[5] = {1, 2, 3, 4, 5};
    int* ptr_array = array;
    cout << "Array name address: " << ptr_array << "\n";
    cout << "First element adderss: " << &array[0] << "\n";
    cout << "pointer by arithmetic: " << *(ptr_array + 1) << "\n";
    cout << "pointer by arithmetic: " << *(ptr_array + 2) << "\n";


    return 0;
}
