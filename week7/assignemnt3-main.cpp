#include "Inventory.h"
#include "Product.h"
#include "Inventory.cpp"
#include "Product.cpp"
#include <iostream>
#include <limits>
#include <vector>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;



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



//Enters book info into vector
Product userEnteredProduct() {
    string name;
    string id;
    double price;
    int quantity;

    cout << "Enter the product name: ";
    getline(cin, name);

    cout << "Enter the product ID: ";
    getline(cin, id);

    cout << "Enter the price: ";
    price = getDoubleInput();

    cout << "Enter the quantity: ";
    quantity = getIntInput();

    return Product(name, id, price, quantity);

}



//Displays the menu for the user
int displayMenu() {
    cout << "\n-------- LIBRARY MANAGEMENT SYSTEM --------\n";
    cout << "1. Add Products to Inventory\n";
    cout << "2. Display Inventory\n";
    cout << "3. Search \n";
    cout << "4. Update Product\n";
    cout << "5. Add Stock\n";
    cout << "6. Remove Stock\n";
    cout << "7. Display Inventory Statistics\n";
    cout << "8. Exit System\n";
    cout << "Please enter your choice (1-8): ";

    return getIntInput();

}

 
//Main function
int main() {   
    bool running = true;
    Inventory inventory;
    inventory.addProduct(Product("Product Name", "Product ID", 15.99, 4));

    while (running == true) {

        int choice = displayMenu();
        //Book* book = nullptr;


        switch (choice) {
         
            case 1: //Add a whole product
                inventory.addProduct(userEnteredProduct());
                break;

            case 2: //Display all products
                inventory.getAllProducts();
                break;

            case 3: //Search for specific product

                break;
            case 4: //Updates Product info
                inventory.updateProductInfo();
                break;
            case 5: //Adds stock

                break;
            case 6: //Removes stock

                break;
            case 7: //Display inventory statistics

                break;

            case 8: // Exit case
                cout << "\nExiting Inventory System...\n";
                running = false;
                break;

            default: // Error/invalid input catch
                cout << "\nInvalid choice. Please enter another.\n";
        }

    }

    return 0;


}
