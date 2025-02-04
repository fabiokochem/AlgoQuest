#include <iostream>
#include <unordered_map>

/*
Dictionaries in Strings are used to store the frequency of characters in a string. It is a very useful data structure to solve problems related to strings, and is important to know how to use it. 

The steps are as follows:
    - Create a dictionary
    - Iterate through the string
    - For each character, check if it is in the dictionary
    - If it is, increment the value of the character
    - If it is not, add the character to the dictionary with a value of 1
    - Print the dictionary

Time Complexity: O(n)
*/
void dictionary(const std::string& str) {
    std::unordered_map<char, int> charFrequency;

    for (char ch : str) {
        charFrequency[ch]++;
    }

    for (const auto& pair : charFrequency) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}

int main() {
    std::string input = "AABAACAADAABAAABAA";
    dictionary(input);
    
    return 0;
}