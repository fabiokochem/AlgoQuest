/*
Memoization is an optimization technique used to improve the performance of recursive algorithms by storing the results of expensive function calls and reusing them when the same inputs occur again. It is particularly useful in dynamic programming problems where overlapping subproblems exist.

Why use memoization?
- Avoids redundant computations.
- Reduces time complexity by storing intermediate results.
- Makes recursive solutions more efficient.

Example:
Consider the Fibonacci sequence, where each number is the sum of the two preceding ones. A naive recursive solution has exponential time complexity (O(2^n)) due to repeated calculations. Using memoization, we can reduce the time complexity to O(n).

Below is an implementation of the Fibonacci sequence using memoization.
*/

#include <iostream>
#include <vector>
using namespace std;

int fibonacci(int n, vector<int>& memo) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);
    return memo[n];
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<int> memo(n + 1, -1);

    int result = fibonacci(n, memo);
    cout << "Fibonacci(" << n << ") = " << result << endl;

    return 0;
}