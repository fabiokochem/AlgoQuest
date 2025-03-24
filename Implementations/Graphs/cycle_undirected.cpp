/*
Cycle detection in an undirected graph is the process of determining whether 
a graph contains at least one cycle. A cycle is a path that starts and ends 
at the same vertex, with all edges and vertices being distinct (except for 
the starting and ending vertex).

How to Use:
    1. Represent the graph using an adjacency list.
    2. Call the `isCyclic` function, passing the number of vertices and the adjacency list.
    3. The function will return `true` if a cycle exists, otherwise `false`.

Implementation:
    - Use Depth First Search (DFS) to traverse the graph.
    - Keep track of visited nodes and their parent nodes.
    - If a visited node is encountered that is not the parent of the current node, 
    a cycle exists.

Time Complexity:
    - O(V + E), where V is the number of vertices and E is the number of edges.
    This is because each vertex and edge is visited once in the DFS traversal.
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool dfs(int node, int parent, vector<bool>& visited, const vector<vector<int>>& adj) {
    visited[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, node, visited, adj)) {
                return true;
            }
        } else if (neighbor != parent) {
            return true;
        }
    }

    return false;
}

bool isCyclic(int V, const vector<vector<int>>& adj) {
    vector<bool> visited(V, false);

    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            if (dfs(i, -1, visited, adj)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int V = 5;
    vector<vector<int>> adj(V);

    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);
    adj[3].push_back(4);
    adj[4].push_back(3);
    adj[4].push_back(1);
    adj[1].push_back(4);

    if (isCyclic(V, adj)) {
        cout << "The graph contains a cycle." << endl;
    } else {
        cout << "The graph does not contain a cycle." << endl;
    }

    return 0;
}