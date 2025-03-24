/*
Articulation Points in a graph are vertices that, when removed along with their associated edges, increase the number of connected components in the graph. These points are critical for understanding the structure and resilience of a graph.

Articulation points are used in network design, fault tolerance analysis, and understanding the vulnerability of networks. For example, in a communication network, articulation points represent nodes whose failure would disrupt communication between other nodes.

The algorithm to find articulation points is based on Depth First Search (DFS). During DFS traversal, we calculate two values for each vertex:
    1. Discovery Time (disc): The time when a vertex is first visited.
    2. Lowest Point (low): The lowest discovery time reachable from the vertex.

A vertex is an articulation point if:
    1. It is the root of the DFS tree and has two or more children.
    2. It is not the root, and there exists a child such that no vertex in the subtree rooted at that child has a back edge to one of the ancestors of the vertex.

Time Complexity: The time complexity of finding articulation points is O(V + E), where V is the number of vertices and E is the number of edges in the graph.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void findArticulationPoints(int u, int parent, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& disc, vector<int>& low, vector<bool>& isArticulation, int& time) {
    visited[u] = true;
    disc[u] = low[u] = ++time;
    int children = 0;

    for (int v : adj[u]) {
        if (!visited[v]) {
            children++;
            findArticulationPoints(v, u, adj, visited, disc, low, isArticulation, time);

            low[u] = min(low[u], low[v]);

            if (parent != -1 && low[v] >= disc[u]) {
                isArticulation[u] = true;
            }
        } else if (v != parent) {
            low[u] = min(low[u], disc[v]);
        }
    }

    if (parent == -1 && children > 1) {
        isArticulation[u] = true;
    }
}

void findArticulationPointsInGraph(int n, vector<vector<int>>& adj) {
    vector<bool> visited(n, false);
    vector<int> disc(n, -1), low(n, -1);
    vector<bool> isArticulation(n, false);
    int time = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            findArticulationPoints(i, -1, adj, visited, disc, low, isArticulation, time);
        }
    }

    cout << "Articulation Points: ";
    for (int i = 0; i < n; i++) {
        if (isArticulation[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    int n = 5;
    vector<vector<int>> adj(n);

    adj[0] = {1, 2};
    adj[1] = {0, 2};
    adj[2] = {0, 1, 3, 4};
    adj[3] = {2, 4};
    adj[4] = {2, 3};

    findArticulationPointsInGraph(n, adj);

    return 0;
}