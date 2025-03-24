/*
The Floyd-Warshall algorithm is a dynamic programming algorithm used to find the shortest paths 
between all pairs of vertices in a weighted graph. It works for both directed and undirected graphs 

How it works:
    - The algorithm iteratively improves the shortest path estimates by considering each vertex as an 
    intermediate point in the path.
    - It uses a 2D matrix (distance matrix) to store the shortest distances between every pair of vertices.
    - Initially, the distance between two vertices is set to the weight of the edge connecting them 
    (or infinity if no edge exists), and the distance from a vertex to itself is set to 0.
    - For each vertex k, the algorithm updates the distance matrix by checking if a path through k 
    provides a shorter route between any two vertices i and j.

How to use:
    - Represent the graph as an adjacency matrix, where graph[i][j] is the weight of the edge from vertex i to j.
    - If there is no edge between i and j, set graph[i][j] to a large value (e.g., infinity).
    - Pass the adjacency matrix to the Floyd-Warshall function to compute the shortest paths.
    - After execution, the distance matrix will contain the shortest distances between all pairs of vertices.

Time Complexity:
    - The Floyd-Warshall algorithm has a time complexity of O(V^3), where V is the number of vertices in the graph.
    - This is because it involves three nested loops iterating over all pairs of vertices and an intermediate vertex.
 */
#include <iostream>
#include <vector>
#include <limits>

const int INF = std::numeric_limits<int>::max();

void floydWarshall(std::vector<std::vector<int>>& graph) {
    int V = graph.size();
    std::vector<std::vector<int>> dist = graph;

    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (dist[i][j] == INF) {
                std::cout << "INF ";
            } else {
                std::cout << dist[i][j] << " ";
            }
        }
        std::cout << "\n";
    }
}

int main() {
    std::vector<std::vector<int>> graph = {
        {0, 3, INF, INF},
        {2, 0, INF, INF},
        {INF, 7, 0, 1},
        {6, INF, INF, 0}
    };

    floydWarshall(graph);

    return 0;
}