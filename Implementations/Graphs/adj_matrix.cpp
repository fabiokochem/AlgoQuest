/*
An adjacency matrix is a 2D array used to represent a graph. 
Each cell in the matrix indicates whether there is an edge between two vertices.
For an undirected graph, the matrix is symmetric. For a directed graph, it is not.

How to Use:
    - Use a 2D vector or array to store the adjacency matrix.
    - If there is an edge between vertex `i` and vertex `j`, set matrix[i][j] = 1 (or the weight of the edge).
    - For undirected graphs, also set matrix[j][i] = 1 (or the weight).
    - For no edge, set matrix[i][j] = 0.

Time Complexity:
    - Space Complexity: O(V^2), where V is the number of vertices.
    - Adding an edge: O(1).
    - Checking if an edge exists: O(1).
    - Iterating over all neighbors of a vertex: O(V).
*/

#include <iostream>
#include <vector>
using namespace std;

void printAdjMatrix(const vector<vector<int>>& adjMatrix) {
    for (const auto& row : adjMatrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    int vertices = 5;
    vector<vector<int>> adjMatrix(vertices, vector<int>(vertices, 0));

    adjMatrix[0][1] = 1;
    adjMatrix[1][0] = 1;

    adjMatrix[1][2] = 1;
    adjMatrix[2][1] = 1;

    adjMatrix[3][4] = 1;
    adjMatrix[4][3] = 1;

    cout << "Adjacency Matrix:" << endl;
    printAdjMatrix(adjMatrix);

    return 0;
}