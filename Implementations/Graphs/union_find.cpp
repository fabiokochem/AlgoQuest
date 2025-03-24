/*
Union-Find (also known as Disjoint Set Union, DSU) is a data structure that keeps track of a set of elements partitioned into disjoint (non-overlapping) subsets. It supports two primary operations:
    1. Find: Determine which subset a particular element is in. This can be used to check if two elements are in the same subset.
    2. Union: Join two subsets into a single subset.

Union-Find is commonly used in graph-related algorithms, such as Kruskal's Minimum Spanning Tree algorithm and finding connected components in a graph.

How to Use:
    - Initialize the Union-Find structure with `n` elements.
    - Use `find(x)` to get the representative (or root) of the subset containing `x`.
    - Use `union(x, y)` to merge the subsets containing `x` and `y`.
=
The implementation uses two optimizations:
    1. Path Compression: Speeds up the `find` operation by making nodes point directly to the root.
    2. Union by Rank: Ensures the smaller tree is merged under the larger tree to keep the structure balanced.

Time Complexity: Each `find` and `union` operation runs in nearly constant time, specifically O(α(n)), where α(n) is the inverse Ackermann function, which grows extremely slowly and is practically constant for all reasonable input sizes.
*/

#include <vector>
using namespace std;

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int n) {
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

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};