#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

/*
The Naive String Search Algorithm is the simplest algorithm for string searching. It checks for the occurrence of a pattern in a text by checking each character of the pattern against each character of the text. If a mismatch is found, it moves to the next character in the text and starts the comparison again. This process is repeated until the pattern is found in the text or the end of the text is reached.

The steps are as follows:
    - Start from the first character of the text.
    - Check if the first character of the pattern matches the current character of the text.
    - If there is a match, check the next character of the pattern against the next character of the text.
    - If there is a mismatch, move to the next character of the text and start the comparison again.
    - Repeat the process until the pattern is found in the text or the end of the text is reached.

Time Complexity: O(m*n)
*/
void naiveStringSearch(string &text, string &pattern) {
    int n = text.length();
    int m = pattern.length();

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == m) {
            cout << "Pattern found at index " << i << endl;
        }
    }
}

int main() {
    string text = "AABAACAADAABAAABAA";
    string pattern = "AABA";
    naiveStringSearch(text, pattern);
    return 0;
}
