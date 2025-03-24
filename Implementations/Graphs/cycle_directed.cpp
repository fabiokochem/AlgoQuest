/**
Cycle detection in a directed graph is the process of determining whether 
there exists a cycle in the graph. A cycle is a path that starts and ends 
at the same vertex, with at least one edge traversed.

How to Use:
    - Represent the graph using an adjacency list.
    - Use Depth First Search (DFS) to traverse the graph.
    - Maintain two arrays: `visited` to track visited nodes and `recStack` 
    to track nodes in the current recursion stack.
    - If a node is revisited while it is still in the recursion stack, a cycle exists.

Implementation:
    - Use DFS to explore each node.
    - Mark the node as visited and add it to the recursion stack.
    - For each neighbor, recursively check for cycles.
    - If a cycle is detected, return true.
    - After exploring all neighbors, remove the node from the recursion stack.

Time Complexity:
    - The time complexity of this algorithm is O(V + E), where V is the number 
    of vertices and E is the number of edges in the graph. This is because 
    each vertex and edge is visited once during the DFS traversal.
*/

#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) : V(V), adj(V) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    bool isCyclicUtil(int v, vector<bool>& visited, vector<bool>& recStack) {
        visited[v] = true;
        recStack[v] = true;

        for (int neighbor : adj[v]) {
            if (!visited[neighbor] && isCyclicUtil(neighbor, visited, recStack))
                return true;
            else if (recStack[neighbor])
                return true;
        }

        recStack[v] = false;
        return false;
    }

    bool isCyclic() {
        vector<bool> visited(V, false);
        vector<bool> recStack(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i] && isCyclicUtil(i, visited, recStack))
                return true;
        }
        return false;
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    if (g.isCyclic())
        cout << "Graph contains a cycle\n";
    else
        cout << "Graph does not contain a cycle\n";

    return 0;
}