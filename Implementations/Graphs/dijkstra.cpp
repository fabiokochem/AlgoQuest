/*
Dijkstra's algorithm is a graph search algorithm that solves the single-source shortest path problem 
for a graph with non-negative edge weights. It computes the shortest path from a source vertex to all 
other vertices in the graph.

How to Use:
    1. Represent the graph using an adjacency list or adjacency matrix.
    2. Provide the source vertex from which the shortest paths will be calculated.
    3. The algorithm will return the shortest distances from the source to all other vertices.

Implementation Steps:
    1. Initialize a priority queue (min-heap) to store vertices based on their current shortest distance.
    2. Maintain a distance array to store the shortest distance from the source to each vertex. Initialize 
    all distances to infinity, except the source vertex which is set to 0.
    3. While the priority queue is not empty:
    a. Extract the vertex with the smallest distance.
    b. For each neighbor of the extracted vertex, calculate the potential new distance.
    c. If the new distance is smaller than the currently known distance, update it and push the neighbor 
        into the priority queue.

Time Complexity:
    - Using a priority queue (min-heap), the time complexity is O((V + E)log(V)), where V is the number 
    of vertices and E is the number of edges.
    - Space complexity is O(V + E) for the adjacency list and O(V) for the distance array.
 */

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

void dijkstra(int source, const vector<vector<pair<int, int>>>& graph, vector<int>& distances) {
    int n = graph.size();
    distances.assign(n, INF);
    distances[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int currentDistance = pq.top().first;
        int currentVertex = pq.top().second;
        pq.pop();

        if (currentDistance > distances[currentVertex]) continue;

        for (const auto& neighbor : graph[currentVertex]) {
            int nextVertex = neighbor.first;
            int weight = neighbor.second;

            if (distances[currentVertex] + weight < distances[nextVertex]) {
                distances[nextVertex] = distances[currentVertex] + weight;
                pq.push({distances[nextVertex], nextVertex});
            }
        }
    }
}

int main() {
    int n = 5;
    vector<vector<pair<int, int>>> graph(n);

    graph[0].push_back({1, 2});
    graph[0].push_back({2, 4});
    graph[1].push_back({2, 1});
    graph[1].push_back({3, 7});
    graph[2].push_back({4, 3});
    graph[3].push_back({4, 1});

    vector<int> distances;
    int source = 0;

    dijkstra(source, graph, distances);

    cout << "Shortest distances from source " << source << ":\n";
    for (int i = 0; i < distances.size(); ++i) {
        cout << "Vertex " << i << ": " << (distances[i] == INF ? -1 : distances[i]) << "\n";
    }

    return 0;
}