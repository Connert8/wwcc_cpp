#include <iostream>
#include <string>

int main() {
    // Get user's name
    std::string name;
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);

    // Greet the user
    std::cout << "Hello, " << name << "!" << std::endl;
    std::cout << "Welcome to C++ programming!" << std::endl;

    return 0;
}