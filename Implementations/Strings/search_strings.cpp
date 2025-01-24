#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

/*
Searching in strings involves finding a substring or character within a given string. Most programming languages provide built-in functions to search for substrings or characters in strings. 

So from this, will be presented:
    - Searching for a Character in a String
    - Searching for a Substring in a String
    - Searching Backwards
    - Checking for Existence
*/

// Searching for a character in a string. Time Complexity: O(n)
bool searchChar(string& str, char c) {
    for (char ch : str) {
        if (ch == c) {
            return true;
        }
    }
    return false;
}

// Searching for a substring in a string. Time Complexity: O(n*m)
bool searchSubstring(string& str, string& sub) {
    for (int i = 0; i <= str.size() - sub.size(); i++) {
        int j;
        for (j = 0; j < sub.size(); j++) {
            if (str[i + j] != sub[j]) {
                break;
            }
        }
        if (j == sub.size()) {
            return true;
        }
    }
    return false;
}

// Searching backwards. Time Complexity: O(n)
bool searchBackwards(string& str, char c) {
    for (int i = str.size() - 1; i >= 0; i--) {
        if (str[i] == c) {
            return true;
        }
    }
    return false;
}

// Checking for existence. Time Complexity: O(n)
bool checkExistence(const string& str, const string& sub) {
    return str.find(sub) != string::npos;
}

int main(){
    string str = "Algo Quest!";
    char c = 'Q';
    string sub = "Quest";

    cout << "Searching for character '" << c << "' in string: " << (searchChar(str, c) ? "Found" : "Not found") << endl;
    cout << "Searching for substring '" << sub << "' in string: " << (searchSubstring(str, sub) ? "Found" : "Not found") << endl;
    cout << "Searching backwards for character '" << c << "' in string: " << (searchBackwards(str, c) ? "Found" : "Not found") << endl;
    cout << "Checking for existence of substring '" << sub << "' in string: " << (checkExistence(str, sub) ? "Found" : "Not found") << endl;

    return 0;
}
