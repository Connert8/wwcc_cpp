#include <iostream>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

/*
NOTE:

I'm still figuring out how to pass a struct array by reference.
Everything should be better written in the next assignment.
There's still some things I'm not really understanding, so I'll be learning more about them before the midterm.
'
*/


//Struct Initialization
struct moviInfo {
    string title;
    string director;
    int year;
    int duration;
    double rating;
    string genre;
};

//Average movie rating function
//I'm not sure what the * operator means in passing the struct array
double averageMovieRating(const moviInfo* movies) {
    double sum = 0;
    //Calculating the sum of ratings
    for (int i = 0; i < 3; i++) {
        sum += movies[i].rating;
    }

    //Actual average calculation
    return (sum/3);

}


//Longest movie function
string longestMovie(const moviInfo* movies) {
    //Goes through the duration and compares to the next movie
    string longest;
    for (int i = 0; i < 3; i++) {
        int duramo1 = movies[i].duration;
        //Not sure how to do this without going out of range
        int duramo2 = movies[i+1].duration;

        if (duramo1 > duramo2) {
            longest = movies[i].title;
        }
        else {
            continue;
        }
    }
    return longest;
}

//Movies after a user input date function
//I'm not sure what type to make this function and what to return
string moviesAfterDate(const moviInfo* movies, int date) {
    //checks every movies year to see if longer than the input
    for (int i = 0; i < 3; i++) {
        int movieDate = movies[i].year;
        if (movieDate > date) {
            cout << movies[i].title << " " << "(" << movies[i].year << ")" << endl;
        }
        else {
            continue;
        }
    }
    return " ";

}


//Main function
int main() {
    //Initializing array
    int date = 0;
    moviInfo movies[3];

    //For the length of movies, enter all the data
    for (int i = 0; i < 3; i++) {
        cout << " - Enter info for movie #" << i + 1 << ":" << endl;
        
        cout << "Enter the title: ";
        getline(cin, movies[i].title);

        cout << "\nEnter Director: ";
        getline(cin, movies[i].director);

        cout << "\nEnter year: ";
        cin >> movies[i].year;
        
        cout << "\nEnter Duration (minutes): ";
        cin >> movies[i].duration;

        cout << "\nEnter Rating (0-10): ";
        cin >> fixed >> setprecision(1) >> movies[i].rating;

        cout << "\nEnter Genre: ";
        getline(cin, movies[i].genre);

    }

    //Outputting the data
    cout << "\nYOUR MOVIE COLLECTION:" << endl;
    cout << "---------------------------------------" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << ".   ";
        cout << "Movie title: " << movies[i].title << endl;
        cout << "     Movie director: " << movies[i].director << endl;
        cout << "     Movie year: " << movies[i].year << endl;
        cout << "     Movie duration: " << movies[i].duration << endl;
        cout << "     Movie rating: " << fixed << setprecision(1) << movies[i].rating << endl;
        cout << "     Movie genre: " << movies[i].genre << endl;
        cout << endl;

    }

    //Final output with function calling
    cout << "Average rating is: " << fixed << setprecision(1) << averageMovieRating(movies) << endl;
    cout << "Longest movie is: " << longestMovie(movies) << endl;
    cout << "Enter a year to find movies released after that year: ";
    cin >> date;
    cout << "Movies released after the year " << date << ": " << endl;; 
    cout << "- " << moviesAfterDate(movies, date) << endl;

    return 0;
}

