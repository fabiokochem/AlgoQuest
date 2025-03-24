/*
Min-Cut in a graph is a way to partition the vertices of a graph into two disjoint subsets 
such that the total weight of the edges crossing the subsets is minimized. It is a fundamental 
problem in graph theory with applications in network reliability, clustering, and image segmentation.

How to Use:
    - Represent the graph using an adjacency matrix or adjacency list.
    - Use algorithms like Stoer-Wagner or Max-Flow Min-Cut theorem to compute the min-cut.
    - The output will be the minimum cut value and the partition of vertices.

Time Complexity:
    - The Stoer-Wagner algorithm runs in O(V^3), where V is the number of vertices in the graph.
 */

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int minCut(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> vertices(n);
    for (int i = 0; i < n; ++i) vertices[i] = i;

    int min_cut = INT_MAX;

    while (n > 1) {
        vector<int> weights(n, 0);
        int prev = 0;

        for (int i = 1; i < n; ++i) {
            weights[vertices[i]] += graph[vertices[prev]][vertices[i]];
            prev = i;
        }

        int last = prev;
        for (int i = 1; i < n; ++i) {
            int max_weight = -1, max_index = -1;
            for (int j = 1; j < n; ++j) {
                if (weights[vertices[j]] > max_weight) {
                    max_weight = weights[vertices[j]];
                    max_index = j;
                }
            }

            if (i == n - 1) {
                min_cut = min(min_cut, max_weight);
                for (int j = 0; j < n; ++j) {
                    graph[vertices[last]][vertices[j]] += graph[vertices[max_index]][vertices[j]];
                    graph[vertices[j]][vertices[last]] += graph[vertices[j]][vertices[max_index]];
                }
                vertices.erase(vertices.begin() + max_index);
                --n;
                break;
            }

            weights[vertices[max_index]] = -1;
            last = max_index;
            for (int j = 1; j < n; ++j) {
                if (weights[vertices[j]] != -1) {
                    weights[vertices[j]] += graph[vertices[last]][vertices[j]];
                }
            }
        }
    }

    return min_cut;
}

int main() {
    vector<vector<int>> graph = {
        {0, 3, 3, 0},
        {3, 0, 1, 3},
        {3, 1, 0, 2},
        {0, 3, 2, 0}
    };

    cout << "The minimum cut of the graph is: " << minCut(graph) << endl;

    return 0;
}