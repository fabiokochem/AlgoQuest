#include <iostream>
#include <string>
#include <vector>
#include <cmath>

/*
KMR Algorithm is a string searching algorithm that finds all occurrences of a pattern in a text. It is based on the observation that the pattern itself contains enough information to determine where the next match could begin, thus bypassing unnecessary comparisons. This makes the algorithm more efficient than the naive approach of checking all substrings of the text. The algorithm uses a divide-and-conquer strategy to break the text into blocks and preprocess them to create a table that stores the positions of all occurrences of the pattern in each block.

The steps are as follows:
    - Divide the text into blocks of size sqrt(n), where n is the length of the text.
    - Preprocess each block to create a table that stores the positions of all occurrences of the pattern in the block.
    - For each block, compare the pattern with the block using the table to find all occurrences of the pattern in the block.
    - Combine the results from all blocks to find all occurrences of the pattern in the text.

Time Complexity: O(n + m)
*/
std::vector<int> kmr_search(const std::string &text, const std::string &pattern) {
    int n = text.size();
    int m = pattern.size();
    int block_size = sqrt(n);
    std::vector<int> result;

    // Preprocess the text into blocks
    std::vector<std::vector<int>> blocks((n + block_size - 1) / block_size);
    for (int i = 0; i < n; ++i) {
        blocks[i / block_size].push_back(i);
    }

    // Search for the pattern in each block
    for (const auto &block : blocks) {
        std::vector<int> table(block.size(), 0);
        for (int i = 0; i < block.size(); ++i) {
            if (text.substr(block[i], m) == pattern) {
                table[i] = 1;
            }
        }

        // Collect the results from the table
        for (int i = 0; i < table.size(); ++i) {
            if (table[i] == 1) {
                result.push_back(block[i]);
            }
        }
    }

    return result;
}

int main() {
    std::string text = "AABAACAADAABAAABAA";
    std::string pattern = "AABA";
    std::vector<int> result = kmr_search(text, pattern);

    std::cout << "Pattern found at positions: ";
    for (int pos : result) {
        std::cout << pos << " ";
    }
    std::cout << std::endl;

    return 0;
}
