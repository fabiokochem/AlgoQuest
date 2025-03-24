/*
Topological sorting is an ordering of the vertices in a directed acyclic graph (DAG) 
such that for every directed edge u -> v, vertex u comes before vertex v in the ordering.

How to Use:
        1. Ensure the graph is a DAG (Directed Acyclic Graph).
        2. Represent the graph using an adjacency list.
        3. Perform a DFS traversal, keeping track of visited nodes.
        4. Push nodes onto a stack after visiting all their neighbors.
        5. The stack will contain the topological order when all nodes are processed.

Implementation Steps:
    1. Create a visited array to track visited nodes.
    2. Use a stack to store the topological order.
    3. For each unvisited node, perform a DFS.
    4. During the DFS, after visiting all neighbors of a node, push it onto the stack.
    5. Finally, reverse the stack or use it directly to get the topological order.

Time Complexity:
    The time complexity of the algorithm is O(V + E), where V is the number of vertices 
    and E is the number of edges in the graph. This is because each vertex and edge is 
    processed once during the DFS traversal.
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(int node, vector<bool>& visited, stack<int>& topoStack, const vector<vector<int>>& adj) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited, topoStack, adj);
        }
    }
    topoStack.push(node);
}

vector<int> topologicalSort(int V, const vector<vector<int>>& adj) {
    vector<bool> visited(V, false);
    stack<int> topoStack;

    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            dfs(i, visited, topoStack, adj);
        }
    }

    vector<int> topoOrder;
    while (!topoStack.empty()) {
        topoOrder.push_back(topoStack.top());
        topoStack.pop();
    }

    return topoOrder;
}

int main() {
    int V = 6;
    vector<vector<int>> adj(V);

    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    vector<int> topoOrder = topologicalSort(V, adj);

    cout << "Topological Order: ";
    for (int node : topoOrder) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}