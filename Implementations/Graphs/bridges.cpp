/*
Bridges in a graph are edges that, when removed, increase the number of connected components of the graph. 
In other words, a bridge is a critical connection that, if removed, would disconnect part of the graph.

Bridges are useful in network design, articulation point detection, and understanding the structure of a graph.

To find bridges in a graph, we can use Depth First Search (DFS) and keep track of discovery times and the lowest points reachable from each vertex. 
The key idea is that if the lowest point reachable from a vertex `v` is greater than the discovery time of its parent `u`, then the edge (u, v) is a bridge.

Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges in the graph.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void findBridges(int node, int parent, vector<int> &disc, vector<int> &low, vector<bool> &visited, vector<vector<int>> &adj, vector<pair<int, int>> &bridges, int &time) {
    visited[node] = true;
    disc[node] = low[node] = ++time;

    for (int neighbor : adj[node]) {
        if (neighbor == parent) continue;

        if (!visited[neighbor]) {
            findBridges(neighbor, node, disc, low, visited, adj, bridges, time);

            low[node] = min(low[node], low[neighbor]);

            if (low[neighbor] > disc[node]) {
                bridges.push_back({node, neighbor});
            }
        } else {
            low[node] = min(low[node], disc[neighbor]);
        }
    }
}

vector<pair<int, int>> getBridges(int n, vector<vector<int>> &adj) {
    vector<int> disc(n, -1), low(n, -1);
    vector<bool> visited(n, false);
    vector<pair<int, int>> bridges;
    int time = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            findBridges(i, -1, disc, low, visited, adj, bridges, time);
        }
    }

    return bridges;
}

int main() {
    int n = 5;
    vector<vector<int>> adj(n);

    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[1].push_back(3);
    adj[3].push_back(1);
    adj[3].push_back(4);
    adj[4].push_back(3);

    vector<pair<int, int>> bridges = getBridges(n, adj);

    cout << "Bridges in the graph:" << endl;
    for (auto &bridge : bridges) {
        cout << bridge.first << " - " << bridge.second << endl;
    }

    return 0;
}