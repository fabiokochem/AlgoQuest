/*
Kosaraju's Algorithm is a graph algorithm used to find all the Strongly Connected Components (SCCs) in a directed graph. 
A Strongly Connected Component is a maximal subgraph where every vertex is reachable from every other vertex in the subgraph.

How it works:
    1. Perform a Depth First Search (DFS) on the original graph and push vertices onto a stack in the order of their finishing times.
    2. Reverse the graph (reverse the direction of all edges).
    3. Perform DFS on the reversed graph, starting from the vertices in the order they appear in the stack. Each DFS traversal will give one SCC.

Steps to implement:
    1. Create a stack to store the vertices based on their finishing times.
    2. Perform DFS on the original graph and populate the stack.
    3. Reverse the graph.
    4. Perform DFS on the reversed graph using the stack to find SCCs.

Time Complexity:
    - The algorithm runs in O(V + E), where V is the number of vertices and E is the number of edges. This is because each vertex and edge is processed at most twice (once in the original graph and once in the reversed graph).
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Kosaraju {
    int V;
    vector<vector<int>> adj;

public:
    Kosaraju(int vertices) : V(vertices), adj(vertices) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void dfs(int v, vector<bool>& visited, stack<int>& Stack) {
        visited[v] = true;
        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited, Stack);
            }
        }
        Stack.push(v);
    }

    void reverseGraph(vector<vector<int>>& reversedAdj) {
        for (int u = 0; u < V; ++u) {
            for (int v : adj[u]) {
                reversedAdj[v].push_back(u);
            }
        }
    }

    void dfsOnReversed(int v, vector<bool>& visited, vector<int>& component, vector<vector<int>>& reversedAdj) {
        visited[v] = true;
        component.push_back(v);
        for (int neighbor : reversedAdj[v]) {
            if (!visited[neighbor]) {
                dfsOnReversed(neighbor, visited, component, reversedAdj);
            }
        }
    }

    void findSCCs() {
        stack<int> Stack;
        vector<bool> visited(V, false);

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                dfs(i, visited, Stack);
            }
        }

        vector<vector<int>> reversedAdj(V);
        reverseGraph(reversedAdj);

        fill(visited.begin(), visited.end(), false);
        while (!Stack.empty()) {
            int v = Stack.top();
            Stack.pop();

            if (!visited[v]) {
                vector<int> component;
                dfsOnReversed(v, visited, component, reversedAdj);

                cout << "SCC: ";
                for (int node : component) {
                    cout << node << " ";
                }
                cout << endl;
            }
        }
    }
};

int main() {
    Kosaraju graph(5);
    graph.addEdge(0, 2);
    graph.addEdge(2, 1);
    graph.addEdge(1, 0);
    graph.addEdge(0, 3);
    graph.addEdge(3, 4);

    cout << "Strongly Connected Components are:" << endl;
    graph.findSCCs();

    return 0;
}