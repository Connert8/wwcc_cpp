
#include <iostream>
#include <limits>
#include <vector>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;


//Author class
class Author {
private:
    string name;
    int birthyear;

public:
    //Here, my other constructors worked just fine but this one is the only
    //that needed the most changing, I'm not sure why.
    Author() {}
    Author(string n, int by) 
        : name(n), birthyear(by) {}

    //Accessors
    string getAuthorName() const { return name; }
    int getAuthorBirthYear() const { return birthyear; }

    //Mutators
    void setAuthorName (string n) { name = n; }
    void setAuthorBirthYear (int by) { birthyear = by; }

    //Get Author method to print information
    void getAuthor() const {
        cout << " - Author - " << endl;
        cout << "Name: " << name << endl;
        cout << "Year of birth: " << "(" << birthyear << ")"<< "\n" << endl;
        
    }

};

//Book class
class Book {
private:
    int isbn;
    string title;
    int pubyear;
    Author author;

public:
    Book();
    Book(int is, string t, int py, Author a) 
        : isbn(is), title(t), pubyear(py), author(a) {}

    //Accessors
    int getBookIsbn() const { return isbn; }
    string getBookTitle() const { return title; }
    int getBookPublicationYear() const {return pubyear; }
    Author getAuthorInfo() const { return author; }

    //Getter for Book info
    void getBook() const {
        cout << " -- Book -- " << endl;
        cout << title << " (" << pubyear << ")\n";
        cout << "ISBN Number: " << isbn << endl;
        author.getAuthor();
        
    }

    //Setters
    void setBookIsbn (int newi) { isbn = newi; }
    void setBookTitle (string newt) { title = newt; }
    void setPubYear (int newpy) { pubyear = newpy; }


};

//Library Class, holds the vector of books
class Library {
private: 
    string librname;
    int address;
    vector<Book> books;

public:
    Library();
    Library(string l, int ad) 
        : librname(l), address(ad) {}

    //Getters
    string getLibraryName() const { return librname; }
    int getLibraryAddress() const { return address; }
    int getLibraryBookCount() const {return books.size(); }

    //Adds a book to the vector method
    void addBook (const Book& book) {
        books.push_back(book);
        cout << " - ( " << book.getBookTitle() << " )" << " added to library - " << endl;

    }

    //Book finding method
    Book* findBook(const string& title) {
        for (size_t i = 0; i < books.size(); i++) {
            if (books[i].getBookTitle() == title){
                return &books[i];
            }
        }
        return nullptr;
    }

    /*
    I'm not sure how to get this to work properly.
    I get stuck on trying to point to the author name and not the whole object.

    Book* findAuthor(const string& author) {
        for (size_t i = 0; i < books.size(); i++) {
            if (books[i].getAuthorInfo() == author) {
                return &books[i];
            }
        }
        return nullptr;
    }
    */


    //Displays all books in vector method
    void displayAllBooks() const {
        cout << "\nTotal books: " << books.size() << endl;
        cout << "\n -- Details -- \n" << endl;

        for (const Book& book : books) {
            book.getBook();
            cout << endl;
        }
    }

};


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

//Enters the user input into the vector
Author userEnteredAuthor() {
    string name;
    int birthyear;
    cout << "Enter the Author's name: ";
    getline(cin, name);

    cout << "Enter the Author's birth year: ";
    birthyear = getIntInput();

    return Author(name, birthyear);

}

//Enters book info into vector
Book userEnteredBook() {
    string title;
    int pubyear;
    int isbn;
    Author author;

    cout << "Enter the book title: ";
    getline(cin, title);

    cout << "Enter the publication year: ";
    pubyear = getIntInput();

    cout << "Enter the ISBN";
    isbn = getIntInput();

    cout << " - Enter the Author - ";
    author = userEnteredAuthor();

    return Book(isbn, title, pubyear, author);

}


//Displays the menu for the user
int displayMenu() {
    cout << "\n-------- LIBRARY MANAGEMENT SYSTEM --------\n";
    cout << "1. Add Books to Library\n";
    cout << "2. Display Library Catalog\n";
    cout << "3. Search for Book\n";
    cout << "4. Exit\n";
    cout << "Please enter your choice (1-4): ";

    return getIntInput();

}


//Main function
int main() {   
    bool running = true;
    Author a1("George Orwell", 1903);
    Library library("Library of name", 699);
    library.addBook(Book(972, "1984", 1961, a1));
    library.addBook(Book(978, "Hatchet", 2006, {"Gary Paulsen", 1980}));
    library.addBook(Book(975, "The Little Prince", 1943, {"Antoine de Saint-Exupery", 1900}));


    while (running == true) {
        int choice = displayMenu();
        string title;
        Book* book = nullptr;


        switch (choice) {
         
            case 1: // Add Books to library
                cout << "\nAdd a Book: \n";
                library.addBook(userEnteredBook());
                break;

            case 2: // Display Catalogue
                cout << "\n  -- Library Catalogue --  " << endl;
                library.displayAllBooks();
                break;

            case 3: // Search For Books
                cout << "\n-- Search for Books --\n";
                cout << "Enter the title of the book you'd like to find: ";
                getline(cin, title);
                cout << "Books with title/keyword: " << endl;
                library.findBook(title);
                if (book != nullptr) {
                    book->getBook();
                } else {
                    cout << " - None Found -  " << title << endl;
                }
                break;


            case 4: // Exit case
                cout << "\nExiting Library System...\n";
                running = false;
                break;

            default: // Error/invalid input catch
                cout << "\nInvalid choice. Please enter another.\n";
        }

    }

    return 0;


}
