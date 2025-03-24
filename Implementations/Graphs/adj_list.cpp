/*
An adjacency list is a way to represent a graph as a collection of lists. 
Each vertex in the graph has a list of all the vertices it is connected to. 
This representation is efficient in terms of space for sparse graphs and 
allows for quick traversal of neighbors of a vertex.

How to Use:
    1. Define the number of vertices (V) and edges (E).
    2. Use a vector of vectors (or a list of lists) to store the adjacency list.
    3. Add edges to the graph by appending neighbors to the corresponding vertex's list.

Time Complexity:
    - Space Complexity: O(V + E), where V is the number of vertices and E is the number of edges.
    - Adding an edge: O(1).
    - Traversing all neighbors of a vertex: O(degree of vertex).
    - Traversing the entire graph: O(V + E).
*/

#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<vector<int>>& adjList, int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

void printAdjList(const vector<vector<int>>& adjList) {
    for (int i = 0; i < adjList.size(); ++i) {
        cout << i << ": ";
        for (int neighbor : adjList[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

int main() {
    int V = 5;
    vector<vector<int>> adjList(V);

    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 4);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 1, 4);
    addEdge(adjList, 2, 3);
    addEdge(adjList, 3, 4);

    printAdjList(adjList);

    return 0;
}