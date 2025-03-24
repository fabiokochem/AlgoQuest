/*
An Eulerian Path is a trail in a graph that visits every edge exactly once. 
An Eulerian Cycle (or Circuit) is an Eulerian Path that starts and ends at the same vertex.

Conditions for Eulerian Path:
    1. At most two vertices have an odd degree.
    2. All vertices with nonzero degree are connected.

Conditions for Eulerian Cycle:
    1. All vertices with nonzero degree have an even degree.
    2. All vertices with nonzero degree are connected.

How to Use:
    1. Check the graph's degree conditions to determine if it has an Eulerian Path or Cycle.
    2. If conditions are satisfied, use Hierholzer's Algorithm to construct the path or cycle.

The implementation uses Hierholzer's Algorithm:
    1. Start at any vertex with an odd degree (for Eulerian Path) or any vertex (for Eulerian Cycle).
    2. Follow edges one at a time, removing them from the graph.
    3. If you get stuck, backtrack to a previously visited vertex with unused edges.
    4. Continue until all edges are used.

Time Complexity: The algorithm runs in O(E), where E is the number of edges in the graph.
*/

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

void findEulerianPathOrCycle(unordered_map<int, vector<int>>& graph, int start) {
    stack<int> currentPath;
    vector<int> circuit;
    currentPath.push(start);

    while (!currentPath.empty()) {
        int current = currentPath.top();

        if (!graph[current].empty()) {
            int next = graph[current].back();
            graph[current].pop_back();
            currentPath.push(next);
        } else {
            circuit.push_back(current);
            currentPath.pop();
        }
    }

    for (int i = circuit.size() - 1; i >= 0; --i) {
        cout << circuit[i];
        if (i > 0) cout << " -> ";
    }
    cout << endl;
}

int main() {
    unordered_map<int, vector<int>> graph;
    graph[0] = {1, 2};
    graph[1] = {0, 2};
    graph[2] = {0, 1};

    int start = 0;

    findEulerianPathOrCycle(graph, start);

    return 0;
}