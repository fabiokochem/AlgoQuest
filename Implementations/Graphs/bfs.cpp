/**
Breadth-First Search (BFS) Implementation

BFS is a graph traversal algorithm that explores vertices in layers. 
It starts from a given source vertex and explores all its neighbors 
before moving to the next level of neighbors.

How to Use:
    1. Represent the graph using an adjacency list.
    2. Call the bfs function with the graph, source vertex, and number of vertices.
    3. The function will print the order of traversal and return a vector of distances.

Implementation Details:
    - Use a queue to explore vertices level by level.
    - Maintain a visited array to avoid revisiting nodes.
    - Optionally, track distances from the source vertex.

Time Complexity:
    - O(V + E), where V is the number of vertices and E is the number of edges.
    This is because each vertex and edge is processed at most once.
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfs(const vector<vector<int>>& graph, int source, int vertices) {
    vector<bool> visited(vertices, false);
    vector<int> distance(vertices, -1);
    queue<int> q;                 

    visited[source] = true;
    distance[source] = 0;
    q.push(source);

    cout << "BFS Traversal Order: ";
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";

        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                distance[neighbor] = distance[current] + 1;
                q.push(neighbor);
            }
        }
    }
    cout << endl;

    return distance;
}

int main() {
    int vertices = 6;
    vector<vector<int>> graph(vertices);

    graph[0] = {1, 2};
    graph[1] = {0, 3, 4};
    graph[2] = {0, 4};
    graph[3] = {1, 5};
    graph[4] = {1, 2, 5};
    graph[5] = {3, 4};

    int source = 0;
    vector<int> distances = bfs(graph, source, vertices);

    cout << "Distances from source " << source << ": ";
    for (int i = 0; i < vertices; ++i) {
        cout << distances[i] << " ";
    }
    cout << endl;

    return 0;
}