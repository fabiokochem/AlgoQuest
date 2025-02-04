#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

/*
Edit Distance is a problem that is used to find the minimum number of operations required to convert one string to another. The operations that are allowed are:
    - Insertion: Insert a character at any position in the string.
    - Deletion: Delete a character from any position in the string.
    - Substitution: Replace a character at any position in the string with another character.

Leveinshtein Distance is a special case of Edit Distance where the cost of all operations is 1 and this is the most common case of Edit Distance. We will be discussing the Leveinshtein Distance in this implementation. The result that we are looking for is the minimum number of operations required to convert one string to another. From this, we can also find the minimum number of operations required to convert one string to another by using the following formula:
    - If the characters at the current position are the same, then the cost is the same as the cost of converting the strings without the current characters.
    - If the characters at the current position are different, then the cost is the minimum of the following:
        - The cost of converting the strings without the current characters.
        - The cost of converting the strings without the current characters and replacing the characters at the current position.

Time Complexity: O(n*m) where n is the length of the first string and m is the length of the second string.
*/
int editDistance(const std::string &str1, const std::string &str2) {
    int n = str1.size();
    int m = str2.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (i == 0) {
                dp[i][j] = j; // If first string is empty, insert all characters of second string
            } else if (j == 0) {
                dp[i][j] = i; // If second string is empty, remove all characters of first string
            } else if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1]; // If characters are the same, no operation needed
            } else {
                dp[i][j] = 1 + std::min({dp[i - 1][j],    // Remove
                                         dp[i][j - 1],    // Insert
                                         dp[i - 1][j - 1] // Replace
                                        });
            }
        }
    }
    return dp[n][m];
}

int main() {
    std::string str1 = "kitten";
    std::string str2 = "sitting";
    
    std::cout << "Edit Distance between " << str1 << " and " << str2 << " is " << editDistance(str1, str2) << std::endl;
    return 0;
}