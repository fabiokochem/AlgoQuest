/*
Prim's algorithm is a greedy algorithm used to find the Minimum Spanning Tree (MST) of a weighted, connected, and undirected graph. 
The MST is a subset of the edges of the graph that connects all the vertices together without any cycles and with the minimum possible total edge weight.

How it works:
    1. Start with an arbitrary node and add it to the MST.
    2. At each step, pick the smallest edge that connects a vertex in the MST to a vertex outside the MST.
    3. Repeat until all vertices are included in the MST.

How to use:
    - Input the graph as an adjacency list or adjacency matrix.
    - Use a priority queue (min-heap) to efficiently select the smallest edge.
    - Keep track of visited nodes to avoid cycles.

Implementation:
    - Use a priority queue to store edges with their weights.
    - Maintain a visited array to track nodes already included in the MST.
    - Add edges to the MST until all nodes are included.

Time Complexity:
    - Using an adjacency list and a priority queue, the time complexity is O(E log V), where E is the number of edges and V is the number of vertices.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>

using namespace std;

typedef pair<int, int> Edge;

void primsAlgorithm(int n, vector<vector<Edge>>& graph) {
    vector<bool> visited(n, false);
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    int mstCost = 0;

    pq.push({0, 0});

    while (!pq.empty()) {
        auto [weight, u] = pq.top();
        pq.pop();

        if (visited[u]) continue;

        visited[u] = true;
        mstCost += weight;

        for (auto [w, v] : graph[u]) {
            if (!visited[v]) {
                pq.push({w, v});
            }
        }
    }

    cout << "Total cost of Minimum Spanning Tree: " << mstCost << endl;
}

int main() {
    int n = 5;
    vector<vector<Edge>> graph(n);

    graph[0].push_back({2, 1});
    graph[1].push_back({2, 0});

    graph[0].push_back({3, 3});
    graph[3].push_back({3, 0});

    graph[1].push_back({1, 2});
    graph[2].push_back({1, 1});

    graph[1].push_back({4, 3});
    graph[3].push_back({4, 1});

    graph[2].push_back({5, 4});
    graph[4].push_back({5, 2});

    graph[3].push_back({6, 4});
    graph[4].push_back({6, 3});

    primsAlgorithm(n, graph);

    return 0;
}