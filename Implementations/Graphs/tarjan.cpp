/*
Tarjan's Algorithm is a graph algorithm used to find Strongly Connected Components (SCCs) in a directed graph. 
A Strongly Connected Component is a maximal subgraph where every vertex is reachable from every other vertex in the subgraph.

How it works:
    - It uses Depth First Search (DFS) to traverse the graph.
    - It maintains a discovery time and a low-link value for each vertex.
    - A stack is used to keep track of the vertices in the current DFS path.
    - When a vertex is identified as the root of an SCC, all vertices in the SCC are popped from the stack.

How to use:
    1. Represent the graph using an adjacency list.
    2. Call the Tarjan's algorithm function for each unvisited vertex.
    3. The algorithm will output all SCCs in the graph.

Time Complexity:
    - The algorithm runs in O(V + E), where V is the number of vertices and E is the number of edges in the graph.
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class TarjanSCC {
private:
    vector<vector<int>> adj;
    vector<int> disc;
    vector<int> low;
    vector<bool> inStack;
    stack<int> st;
    int time;
    vector<vector<int>> sccs;

    void dfs(int u) {
        disc[u] = low[u] = time++;
        st.push(u);
        inStack[u] = true;

        for (int v : adj[u]) {
            if (disc[v] == -1) {
                dfs(v);
                low[u] = min(low[u], low[v]);
            } else if (inStack[v]) {
                low[u] = min(low[u], disc[v]);
            }
        }

        if (low[u] == disc[u]) {
            vector<int> scc;
            while (true) {
                int v = st.top();
                st.pop();
                inStack[v] = false;
                scc.push_back(v);
                if (v == u) break;
            }
            sccs.push_back(scc);
        }
    }

public:
    TarjanSCC(int n) : adj(n), disc(n, -1), low(n, -1), inStack(n, false), time(0) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    vector<vector<int>> findSCCs() {
        for (int i = 0; i < adj.size(); i++) {
            if (disc[i] == -1) {
                dfs(i);
            }
        }
        return sccs;
    }
};

int main() {
    int n = 5;
    TarjanSCC graph(n);

    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.addEdge(1, 3);
    graph.addEdge(3, 4);

    vector<vector<int>> sccs = graph.findSCCs();

    cout << "Strongly Connected Components:" << endl;
    for (const auto& scc : sccs) {
        for (int v : scc) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}