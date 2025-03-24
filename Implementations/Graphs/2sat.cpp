/*
The 2-Satisfiability (2-SAT) problem is a special case of the Boolean Satisfiability Problem (SAT) where each clause in the formula contains exactly two literals. It is used to determine if there exists an assignment of truth values to variables such that the entire formula evaluates to true.

Applications:
    - Circuit design
    - Scheduling problems
    - Logical inference

How to Use:
    1. Represent the problem as a set of implications between variables.
    2. Construct an implication graph where each variable and its negation are nodes, and implications are directed edges.
    3. Use Strongly Connected Components (SCC) to check for contradictions. If a variable and its negation belong to the same SCC, the formula is unsatisfiable.

Implementation:
    1. Build the implication graph.
    2. Use Tarjan's or Kosaraju's algorithm to find SCCs.
    3. Check for contradictions and assign truth values.

Time Complexity:
    - Building the graph: O(n + m), where n is the number of variables and m is the number of clauses.
    - Finding SCCs: O(n + m).
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class TwoSAT {
    int n;
    vector<vector<int>> adj, adjRev;
    vector<int> order, component;
    vector<bool> assignment;
    vector<bool> visited;

public:
    TwoSAT(int variables) : n(variables), adj(2 * variables), adjRev(2 * variables), visited(2 * variables, false), component(2 * variables, -1), assignment(variables, false) {}

    void addImplication(int u, int v) {
        adj[u].push_back(v);
        adjRev[v].push_back(u);
    }

    void addClause(int u, bool uVal, int v, bool vVal) {
        addImplication(u * 2 + !uVal, v * 2 + vVal);
        addImplication(v * 2 + !vVal, u * 2 + uVal);
    }

    void dfs1(int node) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) dfs1(neighbor);
        }
        order.push_back(node);
    }

    void dfs2(int node, int comp) {
        component[node] = comp;
        for (int neighbor : adjRev[node]) {
            if (component[neighbor] == -1) dfs2(neighbor, comp);
        }
    }

    bool solve() {
        for (int i = 0; i < 2 * n; ++i) {
            if (!visited[i]) dfs1(i);
        }

        reverse(order.begin(), order.end());
        int comp = 0;
        for (int node : order) {
            if (component[node] == -1) dfs2(node, comp++);
        }

        for (int i = 0; i < n; ++i) {
            if (component[2 * i] == component[2 * i + 1]) return false;
            assignment[i] = component[2 * i] < component[2 * i + 1];
        }

        return true;
    }

    vector<bool> getAssignment() {
        return assignment;
    }
};

int main() {
    int variables = 2;
    TwoSAT solver(variables);

    solver.addClause(0, true, 1, true);
    solver.addClause(0, false, 1, true);

    if (solver.solve()) {
        cout << "Satisfiable\n";
        vector<bool> result = solver.getAssignment();
        for (int i = 0; i < variables; ++i) {
            cout << "x" << i + 1 << " = " << result[i] << "\n";
        }
    } else {
        cout << "Unsatisfiable\n";
    }

    return 0;
}