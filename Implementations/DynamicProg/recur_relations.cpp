/**
Recurrence relations in dynamic programming are mathematical equations that express the solution of a problem in terms of the solutions of its
smaller subproblems. These relations are the foundation of dynamic programming, as they allow us to break down a complex problem into
simpler, overlapping subproblems that can be solved efficiently. Dynamic programming is used to optimize problems that exhibit two key properties:
    1. Overlapping Subproblems: The problem can be divided into smaller subproblems, and the same subproblems are solved multiple times.
    2. Optimal Substructure: The solution to the problem can be constructed from the solutions of its subproblems.

By solving each subproblem only once and storing its result (memoization), or by solving subproblems iteratively in a bottom-up manner (tabulation), dynamic programming avoids redundant computations and improves efficiency.

Example: Fibonacci Sequence
The Fibonacci sequence is defined as:
    F(n) = F(n-1) + F(n-2), for n > 1
    F(0) = 0, F(1) = 1

This recurrence relation expresses the nth Fibonacci number in terms of
the (n-1)th and (n-2)th Fibonacci numbers.

Complexity:
    - Time Complexity: O(n), as each subproblem is solved once.
    - Space Complexity: O(n) for memoization or O(1) for optimized tabulation.

Implementation:
    Below is an example of solving the Fibonacci sequence using dynamic
    programming with tabulation.
 */
#include <iostream>
#include <vector>

int fibonacci(int n) {
    if (n <= 1) return n;

    std::vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    std::cout << "Fibonacci(" << n << ") = " << fibonacci(n) << std::endl;

    return 0;
}