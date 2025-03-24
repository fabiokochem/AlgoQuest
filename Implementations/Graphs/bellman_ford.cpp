/*
The Bellman-Ford algorithm is used to find the shortest paths from a single source vertex 
to all other vertices in a weighted graph. It works for graphs with negative weight edges, 
unlike Dijkstra's algorithm which fails in such cases. However, it cannot handle graphs 
with negative weight cycles (it detects them instead).

How to Use:
    1. Represent the graph using an edge list (a list of all edges with their weights).
    2. Initialize the distance to the source vertex as 0 and all other vertices as infinity.
    3. Relax all edges |V| - 1 times, where |V| is the number of vertices.
    4. Check for negative weight cycles by performing one more relaxation. If any distance 
    changes, a negative weight cycle exists.

Time Complexity:
    - O(VE), where V is the number of vertices and E is the number of edges.
    - This is because we relax all edges |V| - 1 times, and each relaxation takes O(E) time.
*/

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct Edge {
    int u, v, weight;
};

bool bellmanFord(int vertices, int source, const vector<Edge>& edges, vector<int>& distances) {
    distances.assign(vertices, numeric_limits<int>::max());
    distances[source] = 0;

    for (int i = 0; i < vertices - 1; ++i) {
        for (const auto& edge : edges) {
            if (distances[edge.u] != numeric_limits<int>::max() && 
                distances[edge.u] + edge.weight < distances[edge.v]) {
                distances[edge.v] = distances[edge.u] + edge.weight;
            }
        }
    }

    for (const auto& edge : edges) {
        if (distances[edge.u] != numeric_limits<int>::max() && 
            distances[edge.u] + edge.weight < distances[edge.v]) {
            return false; 
        }
    }

    return true;
}

int main() {
    int vertices, edgesCount, source;
    cout << "Enter the number of vertices and edges: ";
    cin >> vertices >> edgesCount;

    vector<Edge> edges(edgesCount);
    cout << "Enter the edges (u, v, weight):" << endl;
    for (int i = 0; i < edgesCount; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    cout << "Enter the source vertex: ";
    cin >> source;

    vector<int> distances;
    if (bellmanFord(vertices, source, edges, distances)) {
        cout << "Shortest distances from source vertex " << source << ":" << endl;
        for (int i = 0; i < vertices; ++i) {
            if (distances[i] == numeric_limits<int>::max()) {
                cout << "Vertex " << i << ": INF" << endl;
            } else {
                cout << "Vertex " << i << ": " << distances[i] << endl;
            }
        }
    } else {
        cout << "Graph contains a negative weight cycle." << endl;
    }

    return 0;
}