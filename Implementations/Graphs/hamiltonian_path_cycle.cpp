/*
A Hamiltonian Path is a path in an undirected or directed graph that visits each vertex exactly once. 
A Hamiltonian Cycle (or Hamiltonian Circuit) is a Hamiltonian Path that is a cycle, meaning it starts 
and ends at the same vertex.

Hamiltonian paths and cycles are used in various applications such as routing, scheduling, and 
optimization problems. They are particularly important in the Traveling Salesman Problem (TSP).

To find a Hamiltonian Path or Cycle, we can use backtracking. The algorithm tries to add vertices 
to the path one by one, ensuring that each vertex is visited exactly once. If a valid path or cycle 
is found, it is returned.

The time complexity of finding a Hamiltonian Path or Cycle using backtracking is O(N!), where N is 
the number of vertices in the graph. This is because we explore all permutations of vertices.
*/

#include <iostream>
#include <vector>
using namespace std;

class Hamiltonian {
private:
    vector<vector<int>> graph;
    vector<bool> visited;
    vector<int> path;
    int V;

    bool isSafe(int v, int pos) {
        if (!graph[path[pos - 1]][v]) return false;

        if (visited[v]) return false;

        return true;
    }

    bool hamiltonianCycleUtil(int pos) {
        if (pos == V) {
            return graph[path[pos - 1]][path[0]] == 1;
        }

        for (int v = 1; v < V; v++) {
            if (isSafe(v, pos)) {
                path[pos] = v;
                visited[v] = true;

                if (hamiltonianCycleUtil(pos + 1)) return true;

                visited[v] = false;
            }
        }

        return false;
    }

public:
    Hamiltonian(vector<vector<int>> g) : graph(g), V(g.size()) {
        visited.resize(V, false);
        path.resize(V, -1);
    }

    bool findHamiltonianCycle() {
        path[0] = 0;
        visited[0] = true;

        if (!hamiltonianCycleUtil(1)) {
            cout << "No Hamiltonian Cycle found." << endl;
            return false;
        }

        cout << "Hamiltonian Cycle: ";
        for (int i = 0; i < V; i++) {
            cout << path[i] << " ";
        }
        cout << path[0] << endl;
        return true;
    }
};

int main() {
    vector<vector<int>> graph = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };

    Hamiltonian hamiltonian(graph);
    hamiltonian.findHamiltonianCycle();

    return 0;
}