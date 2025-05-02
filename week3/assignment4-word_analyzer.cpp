#include <iostream>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;



// Function prototypes
int countVowels(string &, int &);
int countConsonants(string &, int &);
bool isPalindrome(string &);
char firstLetter(string &);
string reverse(string &);


//Counting Function
int getNumofRuns(int &numofRuns) {
    numofRuns += 1;
    return numofRuns;
}

//Vowel counting function
int countVowels(string &word, int &vowels) {
    //For i in range of the word lenth, check for vowels
    for (int i = 0; i < word.length(); i++) {
        if (word.at(i) == 'a' || word.at(i) == 'A'){
            vowels += 1;
        }
        else if (word.at(i) == 'e' || word.at(i) == 'E'){
            vowels += 1;
        }
        else if (word.at(i) == 'i' || word.at(i) == 'I'){
            vowels += 1;
        }
        else if (word.at(i) == 'o' || word.at(i) == 'O'){
            vowels += 1;
        }
        else if (word.at(i) == 'u' || word.at(i) == 'U'){
            vowels += 1;
        }
        else if (word.at(i) == ' ' || word.at(i) == ' '){
            vowels += 1;
        }
        else {
            vowels = vowels;
        }
    }
    return vowels;
}

//Consonants counting function
int countConsonants(string &word, int &concount) {
    // for i in range of word length, check for abscense of vowels
    for (int i = 0; i < word.length(); i++) {
        if (word.at(i) == 'a' || word.at(i) == 'A'){
            concount = concount;
        }
        else if (word.at(i) == 'e' || word.at(i) == 'E'){
            concount = concount;
        }
        else if (word.at(i) == 'i' || word.at(i) == 'I'){
            concount = concount;
        }
        else if (word.at(i) == 'o' || word.at(i) == 'O'){
            concount = concount;
        }
        else if (word.at(i) == 'u' || word.at(i) == 'U'){
            concount = concount;
        }
        else if (word.at(i) == ' ' || word.at(i) == ' '){
            concount = concount;
        }
        else {
            concount += 1;
        }
    }
    return concount;
}


//Palindrome Function
bool isPalindrome(string &word) {
    //Initializing comparison words
    string loword = "";
    string palitest = "";
    //Making the reverse of the word
    for (int i = word.length(); i > 0; i--) {
        palitest = palitest + (char)tolower(word.at(i-1));
    }
    //Making the word lowercase
    for (int i = 0; i < word.length(); i++) {
        loword = loword + (char)tolower(word[i]);
    }

    //Checking for equality
    if (loword == palitest) {
        return true;
    }
    else {
        return false;
    }

}


//First letter function
char firstLetter(string &word) {
    return word.at(0);
}


//Reverse word fuunction
string reverse(string &word){
    //Initializing reversed word
    string reword = "";
    //Iterating backwards through the word and appending to new word
    for (int i = word.length(); i > 0; i--) {
        reword = reword + word.at(i-1);
    }
    return reword;
}


// Main function
int main() {
    // Initializing and starting program
    int numofRuns = 0;
    int choice;
    string word;
    char quest;
    int vowels = 0;
    int concount = 0;
    cout << "Would you like to analyze another word? (y/n): " << endl;
    cin >> quest;

    //While the user wants to continue, will run here
    while (toupper(quest) == 'Y') {
        string word;
        cout << "Enter a word: ";
        cin >> word;
        cout << "Original Word: " << word << endl;
        cout << "Number of vowels: " << countVowels(word, vowels) << endl;
        cout << "Number of consonants: " << countConsonants(word, concount) << endl;
        cout << "Is palindrome: ";
        //Checks if palindrome is true or false
        if (isPalindrome(word) == 1) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
        cout << "First letter: " << firstLetter(word) << endl;
        cout << "Reversed: " << reverse(word) << endl;

        //End of analyzation display and recursion question
        cout << "Number of words analyzed: " << getNumofRuns(numofRuns) << endl;
        cout << "Would you like to analyze another word? (y/n): " << endl;
        cin >> quest;
        vowels = 0;
        concount = 0;

    }

    //If the user exits
    if (toupper(quest) != 'Y') {
        cout << " -- Program exited -- " << endl;
        cout << "Number of conversions performed: " << numofRuns << endl;
    }

    return 0;
}

