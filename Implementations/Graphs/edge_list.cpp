/*
An edge list is a way to represent a graph as a list of its edges. 
Each edge is represented as a pair (u, v) for an undirected graph or a triplet (u, v, w) 
for a weighted graph, where u and v are the vertices connected by the edge, and w is the weight.

How to Use:
    - Use an edge list when you need to store all edges explicitly.
    - It is particularly useful for algorithms like Kruskal's Minimum Spanning Tree algorithm.
    - It is not efficient for adjacency queries but is space-efficient for sparse graphs.

Implementation:
    - Use a vector of pairs for an unweighted graph.
    - Use a vector of tuples for a weighted graph.

Time Complexity:
    - Space Complexity: O(E), where E is the number of edges.
    - Adding an edge: O(1).
    - Querying adjacency: O(E) (inefficient for dense graphs).

Below is an implementation of an edge list for a weighted graph.
 */

#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int main() {
    int V = 5, E = 6;

    vector<tuple<int, int, int>> edgeList;

    edgeList.push_back({0, 1, 4}); // Edge from 0 to 1 with weight 4
    edgeList.push_back({0, 2, 3}); // Edge from 0 to 2 with weight 3
    edgeList.push_back({1, 2, 1}); // Edge from 1 to 2 with weight 1
    edgeList.push_back({1, 3, 2}); // Edge from 1 to 3 with weight 2
    edgeList.push_back({2, 3, 4}); // Edge from 2 to 3 with weight 4
    edgeList.push_back({3, 4, 2}); // Edge from 3 to 4 with weight 2

    cout << "Edge List:" << endl;
    for (const auto& edge : edgeList) {
        int u, v, w;
        tie(u, v, w) = edge;
        cout << "(" << u << ", " << v << ", " << w << ")" << endl;
    }

    return 0;
}