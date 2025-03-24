/*
Depth First Search (DFS) is a graph traversal algorithm used to explore nodes and edges of a graph. 
It starts at a source node and explores as far as possible along each branch before backtracking.

How to use:
    1. Represent the graph using an adjacency list or adjacency matrix.
    2. Choose a starting node.
    3. Use a stack (or recursion) to traverse the graph.

Implementation:
    - Mark the starting node as visited.
    - Recursively visit all its unvisited neighbors.

Time Complexity:
    - For a graph with V vertices and E edges:
        - Adjacency List: O(V + E)
        - Adjacency Matrix: O(V^2)
*/

#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;
        cout << node << " ";

        for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                        dfs(neighbor, adj, visited);
                }
        }
}

int main() {
        int V = 5;
        vector<vector<int>> adj(V);

        adj[0] = {1, 2};
        adj[1] = {0, 3, 4};
        adj[2] = {0};
        adj[3] = {1};
        adj[4] = {1};

        vector<bool> visited(V, false);

        cout << "DFS Traversal: ";
        dfs(0, adj, visited);

        return 0;
}