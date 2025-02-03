#include <iostream>
#include <string>
#include <vector>

/*
KMP Algorithm is a string searching algorithm that finds all occurrences of a pattern in a text. It is based on the observation that when a mismatch occurs, the pattern itself contains enough information to determine where the next match could begin, thus bypassing unnecessary comparisons. This makes the algorithm more efficient than the naive approach of checking all substrings of the text.

The steps are as follows:
    - Preprocess the pattern to create a prefix table that stores the length of the longest proper prefix that is also a suffix for each prefix of the pattern.
    - Start from the first character of the text.
    - Check if the current character of the text matches the current character of the pattern.
    - If there is a match, move to the next character of the text and pattern.
    - If there is a mismatch, use the prefix table to determine the next position to compare in the pattern.
    - Repeat the process until the pattern is found in the text or the end of the text is reached.

Time Complexity: O(m + n)
*/
void computeLPSArray(const std::string& pattern, std::vector<int>& lps) {
    int length = 0;
    lps[0] = 0;
    int i = 1;
    while (i < pattern.size()) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(const std::string& pattern, const std::string& text) {
    int m = pattern.size();
    int n = text.size();
    std::vector<int> lps(m);
    computeLPSArray(pattern, lps);
    int i = 0;
    int j = 0;
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        if (j == m) {
            std::cout << "Found pattern at index " << i - j << std::endl;
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main(){
    std::string text = "AABAACAADAABAAABAA";
    std::string pattern = "AABA";
    KMPSearch(pattern, text);
    return 0;
}