/*
The Edmonds-Karp algorithm is an implementation of the Ford-Fulkerson method for computing the maximum flow in a flow network. It uses Breadth-First Search (BFS) to find augmenting paths, ensuring that the shortest path (in terms of the number of edges) is used in each iteration. This guarantees a polynomial time complexity.

How to Use:
    1. Represent the flow network as a graph using an adjacency matrix or adjacency list.
    2. Initialize the flow in all edges to 0.
    3. Use BFS to find an augmenting path from the source to the sink.
    4. Augment the flow along the path by the minimum residual capacity of the edges in the path.
    5. Repeat steps 3 and 4 until no more augmenting paths exist.
    6. The sum of the flows leaving the source (or entering the sink) is the maximum flow.

Time Complexity:
    The time complexity of the Edmonds-Karp algorithm is O(V * E^2), where V is the number of vertices and E is the number of edges in the graph. This is because each BFS takes O(E) time, and the number of augmenting paths is bounded by O(V * E).
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>

using namespace std;

const int MAX = 1000;
int capacity[MAX][MAX];
int flow[MAX][MAX];     
vector<int> adj[MAX];

int bfs(int source, int sink, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[source] = -2;
    queue<pair<int, int>> q;
    q.push({source, INT_MAX});

    while (!q.empty()) {
        int current = q.front().first;
        int current_flow = q.front().second;
        q.pop();

        for (int next : adj[current]) {
            if (parent[next] == -1 && capacity[current][next] - flow[current][next] > 0) {
                parent[next] = current;
                int new_flow = min(current_flow, capacity[current][next] - flow[current][next]);
                if (next == sink) {
                    return new_flow;
                }
                q.push({next, new_flow});
            }
        }
    }
    return 0;
}

int edmonds_karp(int source, int sink, int n) {
    memset(flow, 0, sizeof(flow));
    vector<int> parent(n);
    int max_flow = 0;

    int new_flow;
    while ((new_flow = bfs(source, sink, parent)) > 0) {
        max_flow += new_flow;
        int current = sink;
        while (current != source) {
            int prev = parent[current];
            flow[prev][current] += new_flow;
            flow[current][prev] -= new_flow;
            current = prev;
        }
    }
    return max_flow;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        capacity[u][v] += c;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int source, sink;
    cin >> source >> sink;

    cout << "Maximum Flow: " << edmonds_karp(source, sink, n) << endl;

    return 0;
}