#include <iostream>
#include "Inventory.h"
#include <limits>
using namespace std;
/*

    void getOutOfStock() const;
    void getLowStock() const;
    bool removeProduct(const string& name);
    Product* findProduct(const string& name); 


};*/

Inventory::Inventory() {}



void Inventory::getAllProducts() const
{
    cout << "Products in Inventory" << " (" << products.size() << " total):" << endl;
    if (products.empty()) {
        cout << "  No products in inventory." << endl;
        return;
    }

    for (size_t i = 0; i < products.size(); i++) {
        cout << i+1 << ". ";
        products[i].getWholeProduct();
    }
}

void Inventory::addProduct(const Product& product) {
    products.push_back(product);
    cout << "  == Added (" << product.getProductName() << ") to inventory == " << "\n";

}


void Inventory::updateProductInfo(){
    string choice_prod;
    int choice_info;
    string updated_name;
    string updated_id;
    double updated_price = 0.0;
    int updated_quantity = 0;


    cout << "Which product would you like to update?\n  -- (Enter the name of the product) -- \n";
    for (size_t i = 0; i < products.size(); i++) {
        cout << i+1 << ". " << products[i].getProductName() << "\n";
    }
    getline(cin, choice_prod);
    for (size_t i = 0; i < products.size(); i++) {
        if (choice_prod == products[i].getProductName()) {
            cout << "What would you like to update? -- (Enter number beside info) -- \n";
            cout << "1. Name\n2. ID\n3. Price\n4. Quantity\n";
            cin >> choice_info;
            switch (choice_info) {
                case 1: // Name
                    cout << " -- Enter the new product name: ";
                    getline(cin, updated_name);
                    products[i].setProductName(updated_name);
                    break;
                case 2: // ID
                    cout << " -- Enter the new product ID: ";
                    getline(cin, updated_id);
                    products[i].setProductId(updated_id);
                    break;
                case 3: // Price
                    cout << " -- Enter the new product price: ";
                    cin >> updated_price;
                    products[i].setProductPrice(updated_price);
                    break;
                case 4: // Quantity
                    cout << " -- Enter the new product quantity: ";
                    cin >> updated_quantity;
                    products[i].setProductQuantity(updated_quantity);
                    break;
                default: 
                    cout << "Invalid Input - Try Again";

            }

        }
        else {
            cout << " -- Product Not Found -- ";
            continue;
        }
    }


}



/*
#include <iostream>
#include "Library.h"
using namespace std;

// Constructors
Library::Library() : name("Unnamed Library") {}
Library::Library(string n) : name(n) {}

// Accessor
string Library::getName() const { return name; }
int Library::getBookCount() const { return books.size(); }

// Mutator
void Library::setName(string n) { name = n; }

// Book management
void Library::addBook(const Book& book) {
    books.push_back(book);
    cout << "Book added: " << book.getTitle() << endl;
}

bool Library::removeBook(const string& title) {
    for (size_t i = 0; i < books.size(); i++) {
        if (books[i].getTitle() == title) {
            books.erase(books.begin() + i);
            cout << "Book removed: " << title << endl;
            return true;
        }
    }
    cout << "Book not found: " << title << endl;
    return false;
}

Book* Library::findBook(const string& title) {
    for (size_t i = 0; i < books.size(); i++) {
        if (books[i].getTitle() == title) {
            return &books[i];
        }
    }
    return nullptr;
}

// Display
void Library::listAllBooks() const {
    cout << "Books in " << name << " (" << books.size() << " total):" << endl;
    if (books.empty()) {
        cout << "  No books in library." << endl;
        return;
    }

    for (size_t i = 0; i < books.size(); i++) {
        cout << i+1 << ". ";
        books[i].print();
    }
}

void Library::listAvailableBooks() const {
    cout << "Available books in " << name << ":" << endl;
    bool found = false;

    for (size_t i = 0; i < books.size(); i++) {
        if (!books[i].isCheckedOut()) {
            cout << i+1 << ". ";
            books[i].print();
            found = true;
        }
    }

    if (!found) {
        cout << "  No available books." << endl;
    }
}

void Library::listCheckedOutBooks() const {
    cout << "Checked out books in " << name << ":" << endl;
    bool found = false;

    for (size_t i = 0; i < books.size(); i++) {
        if (books[i].isCheckedOut()) {
            cout << i+1 << ". ";
            books[i].print();
            found = true;
        }
    }

    if (!found) {
        cout << "  No books are checked out." << endl;
    }
}
*/