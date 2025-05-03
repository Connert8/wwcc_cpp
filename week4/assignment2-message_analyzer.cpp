#include <iostream>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

/*NOTE:
This program was built mostly on the page in canvas,
Strings In Depth.
Though of course I'll be making it all my own for this program.
I've used it for the functions with strings using the new string manipulation operations.
*/

// Function prototypes
int countCharacters(string &);
int countWords(string &);
int countSentences(string &);
double averageWordLength(string &);
bool containsEmoji(string &);
string longerThanFive(string &);
string properCapital(string &);


//Counting characters function
int countCharacters(string &tMess) {
    int characters = 0;
    //Going through the string checking for spaces/characters
    for (int i = 0; i < tMess.length(); i++) {
        if (tMess[i] == ' ') {
            characters = characters;
        }
        else {
            characters += 1;
        }
    }

    return characters;

}

//Counting words function
int countWords(string &tMess) {
    int wordNum = 0;
    //Checks if the first character starts a word
    if (isalpha(tMess[0])) {
        wordNum += 1;
    }

    //Checks for characters inbetween spaces
    for (int i = 1; i < tMess.length(); i++) {
        if ((isalpha(tMess[i])) && (!isalpha(tMess[i-1]))) {
            wordNum += 1;
        }
    }

    return wordNum;
}

//Counting sentences
int countSentences(string &tMess) {
    int count = 0;
    // Initializes targets for sentence counting
    string target1 = ".";
    string target2 = "!";
    string target3 = "?";
    
    //This structure was used from the canvas page
    //To my understanding, the loop checks over every character and if,
    //it returns a found value, it will then run the code inside
    size_t pos = 0;
    while ((pos = tMess.find(target1, pos)) != string::npos) {
        count += 1;
        pos += target1.length(); 

    }

    pos = 0;
    while ((pos = tMess.find(target2, pos)) != string::npos) {
        count += 1;
        pos += target2.length();  

    }
    
    pos = 0;
    while ((pos = tMess.find(target3, pos)) != string::npos) {
        count += 1;
        pos += target3.length();  

    }


    return count;

}

//Calculating the average word length function
double averageWordLength(string &tMess) {
    //Code from word count to find the denominator
    int wordNum = 0;
    //Checks if the first character starts a word
    if (isalpha(tMess[0])) {
        wordNum += 1;
    }

    //Checks for characters inbetween spaces
    for (int i = 1; i < tMess.length(); i++) {
        if ((isalpha(tMess[i])) && (!isalpha(tMess[i-1]))) {
            wordNum += 1;
        }
    }

    //Code built from canvas page
    //I'm not entirely sure what -stringstream ss(tMess);- does
    //Though I do understand the rest
    double average = 0;
    double sum = 0;
    stringstream ss(tMess);
    string word;
    while (ss >> word) {
        sum = sum + word.length();
    }
   
    average = sum/wordNum;

    return average;
}


//Checking for emojis function
bool containsEmoji(string &tMess) {
    //If in the message == emoji, return true
    if (tMess.find(":)") < tMess.length()) {
        return true;
    }
    else if (tMess.find(":(") < tMess.length()) {
        return true;
    }
    else if (tMess.find(":P") < tMess.length()) {
        return true;
    }
    else if (tMess.find(":D") < tMess.length()) {
        return true;
    }
    else {
        return false;
    }
}

//Finding words longer than 5 characters function
string longerThanFive(string &tMess){
    //Code built from canvas page
    //Same case here, unsure what stringstream ss does
    string word;
    stringstream ss(tMess);
    while (ss >> word) {
        //removing punctuation from words
        word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
        //if tokenized word is greater than 5, output
        if (word.length() > 5 ) {
            cout << "- " << word << endl;
        }
    }

    return " ";
}

//Makes the message properly capitalized function
string properCapital(string &tMess){
    //Sourced from canvas page
    //I'm only unsure on what ":" does between char&c and tMess
    bool makeUpper = true;
    for (char &c : tMess) {
        if (makeUpper && isalpha(c)) {
            c = toupper(c);
            makeUpper = false;
        } 
        else if (c == ' ') {
            makeUpper = true;
        }
    }

    return tMess;

}

// Main function
int main() {
    std::string tMess;
    //Formatting the output
    cout << " -- TEXT MESSAGE ANALYZER -- \n" << "-----------------------------" << endl;
    cout << "Please enter your message:";
    getline(cin, tMess);

    cout << "Message Analysis: \n" << endl;
    //Each line here is the output which contains the function calls
    cout << "Total characters: " << countCharacters(tMess) << endl;
    cout << "Word count: " << countWords(tMess) << endl;
    cout << "Sentence count: " << countSentences(tMess) << endl;
    cout << "Average word length: " << fixed << setprecision(1) << averageWordLength(tMess) << endl;
    cout << "Contains emoji: ";
    if (containsEmoji(tMess) == 1) {
        cout << "Yes\n" << endl;
    }
    else {
        cout << "No\n" << endl;
    }
    cout << "Words longer than 5 characters: \n" << longerThanFive(tMess) << endl;
    cout << "Properly capitalized message: \n" << properCapital(tMess) << endl;



    return 0;
}

