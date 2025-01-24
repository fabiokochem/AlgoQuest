#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

/*
A finite automata is a mathematical model of computation that consists of a set of states and a set of transitions between those states. It is used to recognize patterns in strings by processing each character of the string and moving between states based on the transitions defined in the automata. For this implementation, we will use a deterministic finite automata (DFA) to search for a pattern in a text.

The steps are as follows:
    - Construct the DFA based on the pattern.
    - Process each character of the text and move between states based on the transitions defined in the DFA.
    - If the final state is reached, the pattern is found in the text.

Time Complexity: O(m*|Σ| + n), where m is the length of the pattern, |Σ| is the size of the alphabet, and n is the length of the text.
*/
void computeTF(string pat, int M, int TF[][256]) {
    int i, lps = 0, x;

    // Fill entries in first row
    for (x = 0; x < 256; x++)
        TF[0][x] = 0;
    TF[0][pat[0]] = 1;

    // Fill entries in other rows
    for (i = 1; i < M; i++) {
        // Copy values from row at index lps
        for (x = 0; x < 256; x++)
            TF[i][x] = TF[lps][x];

        // Update the entry corresponding to this character
        TF[i][pat[i]] = i + 1;

        // Update lps for next row to be filled
        if (i < M)
            lps = TF[lps][pat[i]];
    }
}

void search(string pat, string txt) {
    int M = pat.size();
    int N = txt.size();

    int TF[M + 1][256];

    computeTF(pat, M, TF);

    // Process txt over FA.
    int i, j = 0;
    for (i = 0; i < N; i++) {
        j = TF[j][txt[i]];
        if (j == M) {
            cout << "Pattern found at index " << i - M + 1 << endl;
        }
    }
}

int main() {
    string txt = "ABABABACD";
    string pat = "ABABAC";
    search(pat, txt);
    return 0;
}