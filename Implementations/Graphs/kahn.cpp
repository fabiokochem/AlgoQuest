/*
Kahn's Algorithm is a method for performing a topological sort on a Directed Acyclic Graph (DAG). 
It works by iteratively removing nodes with no incoming edges (in-degree of zero) and adding them 
to the topological order. This ensures that all dependencies are resolved before processing a node.

How to Use:
    1. Represent the graph using an adjacency list.
    2. Compute the in-degree (number of incoming edges) for each node.
    3. Use a queue to store nodes with in-degree of zero.
    4. Process nodes from the queue, adding them to the topological order and reducing the in-degree of their neighbors.
    5. If the graph contains a cycle, the algorithm will detect it as not all nodes will be processed.

Implementation Steps:
    1. Initialize an in-degree array for all nodes.
    2. Populate the in-degree array by traversing the adjacency list.
    3. Push all nodes with in-degree zero into a queue.
    4. While the queue is not empty:
        a. Remove a node from the queue and add it to the topological order.
        b. Reduce the in-degree of its neighbors. If any neighbor's in-degree becomes zero, add it to the queue.
    5. If the topological order contains all nodes, the graph is a DAG; otherwise, it contains a cycle.

Time Complexity:
    - O(V + E), where V is the number of vertices and E is the number of edges in the graph.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> kahnAlgorithm(int V, vector<vector<int>>& adj) {
     vector<int> inDegree(V, 0);
     vector<int> topoOrder;
     queue<int> q;

     for (int i = 0; i < V; ++i) {
          for (int neighbor : adj[i]) {
                inDegree[neighbor]++;
          }
     }

     for (int i = 0; i < V; ++i) {
          if (inDegree[i] == 0) {
                q.push(i);
          }
     }

     while (!q.empty()) {
          int node = q.front();
          q.pop();
          topoOrder.push_back(node);    

          for (int neighbor : adj[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                     q.push(neighbor);
                }
          }
     }

     if (topoOrder.size() != V) {
          throw runtime_error("Graph contains a cycle, topological sort not possible.");
     }

     return topoOrder;
}

int main() {
     int V = 6;
     vector<vector<int>> adj = {
          {2, 3},
          {3, 4},
          {},
          {5},
          {5},
          {}
     };

     try {
          vector<int> topoOrder = kahnAlgorithm(V, adj);
          cout << "Topological Order: ";
          for (int node : topoOrder) {
                cout << node << " ";
          }
          cout << endl;
     } catch (const exception& e) {
          cout << e.what() << endl;
     }

     return 0;
}