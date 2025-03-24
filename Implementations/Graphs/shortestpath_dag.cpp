/*
The shortest path in a Directed Acyclic Graph (DAG) is a path between two vertices such that the sum of the weights of its edges is minimized. 
DAGs are special graphs with no cycles, which allows us to use topological sorting to solve the shortest path problem efficiently.

How to use:
    1. Represent the graph using an adjacency list or adjacency matrix.
    2. Perform a topological sort of the vertices.
    3. Relax the edges in the order of the topological sort to calculate the shortest path.

Implementation:
    1. Perform a topological sort of the DAG.
    2. Initialize the distance to the source vertex as 0 and all other vertices as infinity.
    3. Process each vertex in topological order, updating the distances to its neighbors.

Time Complexity:
    - Topological sorting takes O(V + E), where V is the number of vertices and E is the number of edges.
    - Relaxing all edges takes O(E).
    - Overall time complexity: O(V + E).
*/

#include <iostream>
#include <vector>
#include <stack>
#include <limits>

using namespace std;

void topologicalSort(int node, const vector<vector<pair<int, int>>>& adj, vector<bool>& visited, stack<int>& topoStack) {
    visited[node] = true;
    for (const auto& neighbor : adj[node]) {
        if (!visited[neighbor.first]) {
            topologicalSort(neighbor.first, adj, visited, topoStack);
        }
    }
    topoStack.push(node);
}

void shortestPathDAG(int start, const vector<vector<pair<int, int>>>& adj, int V) {
    stack<int> topoStack;
    vector<bool> visited(V, false);

    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            topologicalSort(i, adj, visited, topoStack);
        }
    }

    vector<int> distance(V, numeric_limits<int>::max());
    distance[start] = 0;

    while (!topoStack.empty()) {
        int node = topoStack.top();
        topoStack.pop();

        if (distance[node] != numeric_limits<int>::max()) {
            for (const auto& neighbor : adj[node]) {
                int nextNode = neighbor.first;
                int weight = neighbor.second;
                if (distance[node] + weight < distance[nextNode]) {
                    distance[nextNode] = distance[node] + weight;
                }
            }
        }
    }

    for (int i = 0; i < V; ++i) {
        if (distance[i] == numeric_limits<int>::max()) {
            cout << "INF ";
        } else {
            cout << distance[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    int V = 6;
    vector<vector<pair<int, int>>> adj(V);

    adj[0].emplace_back(1, 2);
    adj[0].emplace_back(4, 1);
    adj[1].emplace_back(2, 3);
    adj[4].emplace_back(2, 2);
    adj[4].emplace_back(5, 4);
    adj[2].emplace_back(3, 6);
    adj[5].emplace_back(3, 1);

    int start = 0;
    shortestPathDAG(start, adj, V);

    return 0;
}