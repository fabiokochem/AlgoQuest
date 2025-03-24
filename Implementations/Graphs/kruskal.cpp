/*=
Kruskal's algorithm is a greedy algorithm used to find the Minimum Spanning Tree (MST) of a connected, undirected graph. 
The MST is a subset of the edges that connects all vertices in the graph with the minimum possible total edge weight, 
and without forming any cycles.

How to Use:
    1. Represent the graph using an edge list where each edge is represented as (weight, u, v).
    2. Sort all edges in non-decreasing order of their weights.
    3. Use a Disjoint Set Union (DSU) or Union-Find data structure to keep track of connected components.
    4. Iterate through the sorted edges and add an edge to the MST if it does not form a cycle (i.e., the two vertices of the edge belong to different components).
    5. Stop when the MST contains exactly (V - 1) edges, where V is the number of vertices.

Time Complexity:
    - Sorting the edges: O(E log E), where E is the number of edges.
    - Union-Find operations: O(E * α(V)), where α(V) is the inverse Ackermann function (nearly constant).
    Overall: O(E log E), as sorting dominates.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DSU {
private:
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) return false;

        // Union by rank
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        return true;
    }
};

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

int kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    int mstWeight = 0;
    int edgesUsed = 0;

    for (const auto& edge : edges) {
        if (dsu.unite(edge.u, edge.v)) {
            mstWeight += edge.weight;
            edgesUsed++;
            if (edgesUsed == n - 1) break;
        }
    }

    return mstWeight;
}

int main() {
    int n = 4;
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    int mstWeight = kruskal(n, edges);
    cout << "Weight of the Minimum Spanning Tree: " << mstWeight << endl;

    return 0;
}