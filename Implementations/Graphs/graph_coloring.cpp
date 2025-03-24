/*
Graph coloring is a way of assigning colors to the vertices of a graph such that no two adjacent vertices share the same color. 
It is a fundamental problem in graph theory with applications in scheduling, register allocation in compilers, and more.

How to Use:
    1. Represent the graph using an adjacency list or adjacency matrix.
    2. Use a graph coloring algorithm to assign colors to vertices.
    3. Ensure that no two adjacent vertices have the same color.

How to Implement:
    1. Use a greedy algorithm for simplicity, which assigns the smallest available color to each vertex.
    2. Traverse the graph and check the colors of adjacent vertices to determine the available colors.

Time Complexity: The time complexity of the greedy graph coloring algorithm is O(V^2 + E), where V is the number of vertices and E is the number of edges.
This is because for each vertex, we may need to check all its neighbors to find an available color.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void graphColoring(const vector<vector<int>>& graph, int V) {
    vector<int> result(V, -1);
    result[0] = 0;

    vector<bool> available(V, true);

    for (int u = 1; u < V; u++) {
        for (int i : graph[u]) {
            if (result[i] != -1) {
                available[result[i]] = false;
            }
        }

        int color;
        for (color = 0; color < V; color++) {
            if (available[color]) {
                break;
            }
        }

        result[u] = color;

        fill(available.begin(), available.end(), true);
    }

    cout << "Vertex\tColor" << endl;
    for (int u = 0; u < V; u++) {
        cout << u << "\t" << result[u] << endl;
    }
}

int main() {
    vector<vector<int>> graph = {
        {1, 2},  
        {0, 2, 3}, 
        {0, 1, 3},
        {1, 2}
    };

    int V = graph.size();
    graphColoring(graph, V);

    return 0;
}