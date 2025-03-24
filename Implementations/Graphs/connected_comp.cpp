/*
Connected Components in a graph refer to the subsets of vertices such that there is a path between any two vertices within the subset, 
and no vertex in the subset is connected to any vertex outside of it. In an undirected graph, connected components are crucial for 
understanding the structure of the graph.

How to Use:
    1. Represent the graph using an adjacency list or adjacency matrix.
    2. Use Depth First Search (DFS) or Breadth First Search (BFS) to traverse the graph.
    3. Keep track of visited nodes to ensure each node is processed only once.
    4. Each DFS/BFS traversal starting from an unvisited node identifies a new connected component.

Time Complexity:
    - Building the adjacency list: O(V + E), where V is the number of vertices and E is the number of edges.
    - DFS traversal: O(V + E), as each vertex and edge is visited once.
    Overall time complexity: O(V + E).
*/

#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& component) {
    visited[node] = true;
    component.push_back(node);
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, component);
        }
    }
}

vector<vector<int>> findConnectedComponents(int n, vector<pair<int, int>>& edges) {
    vector<vector<int>> adj(n);
    for (auto edge : edges) {
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first);
    }

    vector<bool> visited(n, false);
    vector<vector<int>> connectedComponents;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            vector<int> component;
            dfs(i, adj, visited, component);
            connectedComponents.push_back(component);
        }
    }

    return connectedComponents;
}

int main() {
    int n = 6;
    vector<pair<int, int>> edges = {
        {0, 1}, {1, 2}, {3, 4}
    };

    vector<vector<int>> connectedComponents = findConnectedComponents(n, edges);

    cout << "Connected Components:" << endl;
    for (const auto& component : connectedComponents) {
        for (int node : component) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}