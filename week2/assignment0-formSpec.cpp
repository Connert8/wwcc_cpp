#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

int main() {
    // Assignment Example Variables
    int integer_value = 42;
    float float_value = 3.14159265f;
    double double_value = 3.14159265;
    char char_value = 'X';
    const char* string_value = "Hello, World!";

    printf("Format Specifier Practice\n");
    printf("------------------------\n\n");


    
    // My Code    
    
    // Integer Formats
    printf("%d\n", integer_value);
    printf("%x\n", integer_value);
    printf("%p\n", integer_value);
    printf("%o\n", integer_value);
    printf("[%5d]\n", 42);
    printf("[%-5d]\n", 42);

    //Float formats
    printf("Default float value: ", double_value);
    printf("\n");
    printf("%.4f\n", float_value);
    printf("%e\n", float_value);

    //Character/String formats
    printf("%c\n", char_value);
    printf("%.7s\n", string_value);
    printf("[%20d]\n", string_value);

    //Table Practice
    printf("%-10s | %5s | %8s\n", "Name", "Age", "Balance");
    printf("%-10s | %5d | %8.2f\n", "Carter", 20, 120012.98);
    printf("%-10s | %5d | %8.2f\n", "Cartoney", 34, 343.23);

    return 0;
}