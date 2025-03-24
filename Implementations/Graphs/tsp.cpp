/*
The Traveling Salesman Problem (TSP) is a classic optimization problem in graph theory. 
It involves finding the shortest possible route that visits each city exactly once and 
returns to the starting city. The problem is NP-hard, meaning that there is no known 
polynomial-time solution for it.

How to Use:
    - TSP is commonly used in logistics, route optimization, and circuit design.
    - Input: A graph represented as a distance matrix where graph[i][j] is the distance 
        between city i and city j.
    - Output: The minimum cost to visit all cities and return to the starting city.

How to Implement:
    - A common approach to solve TSP is using Dynamic Programming with bitmasking.
    - The state is represented as dp[mask][i], where:
        - mask is a bitmask representing the set of visited cities.
        - i is the current city.
    - Transition: From city i, try visiting all unvisited cities and update the state.

Time Complexity: The time complexity of the DP + bitmasking approach is O(n * 2^n), where n is the number of cities. 
This is feasible for small to medium-sized graphs (n <= 20).
*/

#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

const int INF = INT_MAX;

int tsp(int mask, int pos, const vector<vector<int>>& graph, vector<vector<int>>& dp) {
        int n = graph.size();

        if (mask == (1 << n) - 1) {
                return graph[pos][0];
        }

        if (dp[mask][pos] != -1) {
                return dp[mask][pos];
        }

        int ans = INF;

        for (int city = 0; city < n; city++) {
                if ((mask & (1 << city)) == 0) {
                        int newAns = graph[pos][city] + tsp(mask | (1 << city), city, graph, dp);
                        ans = min(ans, newAns);
                }
        }

        return dp[mask][pos] = ans;
}

int main() {
        vector<vector<int>> graph = {
                {0, 10, 15, 20},
                {10, 0, 35, 25},
                {15, 35, 0, 30},
                {20, 25, 30, 0}
        };

        int n = graph.size();
        vector<vector<int>> dp(1 << n, vector<int>(n, -1));

        int result = tsp(1, 0, graph, dp);

        cout << "The minimum cost of the TSP is: " << result << endl;

        return 0;
}