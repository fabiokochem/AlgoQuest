/*
A bipartite graph, also known as a bigraph, is a graph whose vertices can be divided into two disjoint and independent sets U and V such that every edge connects a vertex in U to one in V. In simpler terms, it is a graph that can be colored using two colors such that no two adjacent vertices share the same color.

Bipartite graphs are commonly used in applications like matching problems (e.g., job assignments, network flow), scheduling, and social network analysis.

To check if a graph is bipartite, we can use a Breadth-First Search (BFS) or Depth-First Search (DFS) to try to color the graph using two colors. If we find a conflict (two adjacent vertices having the same color), the graph is not bipartite.

The time complexity of checking if a graph is bipartite using BFS or DFS is O(V + E), where V is the number of vertices and E is the number of edges in the graph.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isBipartite(vector<vector<int>>& graph, int start, vector<int>& colors) {
    queue<int> q;
    q.push(start);
    colors[start] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : graph[node]) {
            if (colors[neighbor] == -1) {
                colors[neighbor] = 1 - colors[node];
                q.push(neighbor);
            } else if (colors[neighbor] == colors[node]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    vector<vector<int>> graph = {
        {1, 3},
        {0, 2},
        {1, 3},
        {0, 2}
    };

    int n = graph.size();
    vector<int> colors(n, -1);

    bool isGraphBipartite = true;
    for (int i = 0; i < n; i++) {
        if (colors[i] == -1) {
            if (!isBipartite(graph, i, colors)) {
                isGraphBipartite = false;
                break;
            }
        }
    }

    if (isGraphBipartite) {
        cout << "The graph is bipartite." << endl;
    } else {
        cout << "The graph is not bipartite." << endl;
    }

    return 0;
}