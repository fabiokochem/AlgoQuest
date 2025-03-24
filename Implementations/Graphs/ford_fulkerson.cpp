/*
The Ford-Fulkerson algorithm is a method used to compute the maximum flow in a flow network. 
It is based on the idea of augmenting paths, which are paths from the source node to the sink node 
in the residual graph where additional flow can be pushed. The algorithm repeatedly finds such paths 
and augments the flow along them until no more augmenting paths exist.

How to Use:
    1. Represent the flow network as a graph where each edge has a capacity.
    2. Initialize the flow in all edges to 0.
    3. While there exists an augmenting path in the residual graph:
        a. Find the path using a search algorithm (e.g., BFS or DFS).
        b. Determine the minimum residual capacity along the path.
        c. Augment the flow along the path by the minimum residual capacity.
        d. Update the residual graph accordingly.
    4. The maximum flow is the total flow pushed from the source to the sink.

Implementation Steps:
    1. Use an adjacency matrix or adjacency list to represent the graph.
    2. Use BFS or DFS to find augmenting paths in the residual graph.
    3. Update the residual capacities and reverse flows after augmenting.
    4. Repeat until no more augmenting paths exist.

Time Complexity:
    - The time complexity of the Ford-Fulkerson algorithm depends on the method used to find augmenting paths.
    - If BFS is used (Edmonds-Karp implementation), the time complexity is O(V * E^2), where V is the number of vertices and E is the number of edges.
    - If DFS is used, the time complexity is O(E * max_flow), where max_flow is the maximum flow in the network.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>

using namespace std;

bool bfs(vector<vector<int>>& residualGraph, int source, int sink, vector<int>& parent) {
    int V = residualGraph.size();
    vector<bool> visited(V, false);
    queue<int> q;

    q.push(source);
    visited[source] = true;
    parent[source] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++) {
            if (!visited[v] && residualGraph[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;

                if (v == sink) {
                    return true;
                }
            }
        }
    }
    return false;
}

int fordFulkerson(vector<vector<int>>& graph, int source, int sink) {
    int V = graph.size();
    vector<vector<int>> residualGraph = graph;
    vector<int> parent(V);
    int maxFlow = 0;

    while (bfs(residualGraph, source, sink, parent)) {
        int pathFlow = INT_MAX;

        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, residualGraph[u][v]);
        }

        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            residualGraph[u][v] -= pathFlow;
            residualGraph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main() {
    vector<vector<int>> graph = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}
    };

    int source = 0, sink = 5;

    cout << "The maximum possible flow is " << fordFulkerson(graph, source, sink) << endl;

    return 0;
}