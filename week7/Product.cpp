#include <iostream>
#include "Product.h"
#include <limits>
using namespace std;


Product::Product() : name(""), id(""), price(0.0), quantity(0) {}

Product::Product(string n, string i, double p, int q)
    : name(n), id(i), price(p), quantity(q) {}


string Product::getProductName() const { return name; }
string Product::getProductId() const { return id; }
double Product::getProductPrice() const { return price; }
int Product::getProductQuantity() const { return quantity; }

void Product::getWholeProduct() const {
    cout << "\nName: " << getProductName();
    cout << "\nID: " << getProductId();
    cout << "\nPrice: " << getProductPrice();
    cout << "\nQuantity: " << getProductQuantity();


}


void Product::setProductName(string n) {name = n;}
void Product::setProductId(string i) {id = i;}
void Product::setProductPrice(double p) {
    if (p < 0.0) {
        cout << "Invalid Price";
    }
    else {
        price = p;
    }
}
void Product::setProductQuantity(int q) {    
    if (q < 0) {
        cout << "Invalid Quantity";
    }
    else {
        quantity = q;
    }
}



void Product::addStock(int q) {
    if (q < 0) {
        cout << "Invalid Quantity";
    }
    else {
        quantity = q;
    }
}

void Product::removeStock(int q) {
    if (q < 0) {
        cout << "Invalid Quantity";
    }
    else {
        quantity = q;
    }

    
}


/*
void Book::setYear(int y) {
    if (y < 0) {
        cout << "Warning: Invalid year. Setting to 0." << endl;
        year = 0;
    } else {
        year = y;
    }
}

void Book::setISBN(string i) { isbn = i; }

// Functionality
void Book::checkOut() {
    if (checkedOut) {
        cout << "Error: Book is already checked out." << endl;
    } else {
        checkedOut = true;
        cout << "Book checked out successfully." << endl;
    }
}

void Book::returnBook() {
    if (!checkedOut) {
        cout << "Error: Book is not checked out." << endl;
    } else {
        checkedOut = false;
        cout << "Book returned successfully." << endl;
    }
}

// Display
void Book::print() const {
    cout << "\"" << title << "\" by " << author << " (" << year << ")";
    if (!isbn.empty()) {
        cout << " ISBN: " << isbn;
    }
    cout << " - " << (checkedOut ? "Checked Out" : "Available");
    cout << endl;
}
*/