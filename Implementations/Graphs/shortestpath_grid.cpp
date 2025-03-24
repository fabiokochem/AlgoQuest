/*
The shortest path in a grid problem involves finding the minimum number of steps required to travel from a starting cell to a target cell in a 2D grid. The grid may contain obstacles or weights, and the movement is typically restricted to four directions: up, down, left, and right.

How to Use:
    1. Represent the grid as a 2D array where each cell contains information about its state (e.g., walkable, obstacle, or weighted).
    2. Define the starting and target positions.
    3. Use a graph traversal algorithm like Breadth-First Search (BFS) for unweighted grids or Dijkstra's algorithm for weighted grids to compute the shortest path.

Implementation:
    - BFS is commonly used for unweighted grids because it explores all nodes at the current depth level before moving to the next level, ensuring the shortest path is found.
    - Use a queue to store the current position and the number of steps taken.
    - Keep track of visited cells to avoid revisiting them.

Time Complexity:
    - For an `m x n` grid, the time complexity is O(m * n) since each cell is visited at most once.
    - Space complexity is also O(m * n) due to the storage of the visited array and the queue.
*/

#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

const vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int shortestPathInGrid(vector<vector<int>>& grid, pair<int, int> start, pair<int, int> target) {
    int rows = grid.size();
    int cols = grid[0].size();

    if (grid[start.first][start.second] == 1 || grid[target.first][target.second] == 1) {
        return -1;
    }

    queue<pair<pair<int, int>, int>> q;
    q.push({start, 0});

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    visited[start.first][start.second] = true;

    while (!q.empty()) {
        auto [current, steps] = q.front();
        q.pop();

        if (current == target) {
            return steps;
        }

        for (const auto& dir : directions) {
            int newRow = current.first + dir.first;
            int newCol = current.second + dir.second;

            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols &&
                !visited[newRow][newCol] && grid[newRow][newCol] == 0) {
                visited[newRow][newCol] = true;
                q.push({{newRow, newCol}, steps + 1});
            }
        }
    }

    return -1;
}

int main() {
    vector<vector<int>> grid = {
        {0, 0, 0, 1},
        {0, 1, 0, 1},
        {0, 0, 0, 0},
        {1, 1, 0, 0}
    };

    pair<int, int> start = {0, 0};
    pair<int, int> target = {3, 3};

    int result = shortestPathInGrid(grid, start, target);

    if (result != -1) {
        cout << "Shortest path length: " << result << endl;
    } else {
        cout << "No path exists to the target." << endl;
    }

    return 0;
}