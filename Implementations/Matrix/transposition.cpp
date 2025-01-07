#include <iostream>
#include <vector>

using std::vector;

/*
Matrix Transposition involves converting the rows of a matrix into columns and vice-versa. 
To do this, we need to iterate over the rows and columns of the matrix and swap the elements at the corresponding indices.

The steps of the algorithm are as follows:
    - Iterate over the rows and columns of the matrix.
    - Swap the elements at the corresponding indices.

Is important to say that this implementation works for not only square matrices, but also for rectangular matrices (pay attention on it!).

Time Complexity: O(N*M).
*/
void transpose(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> result(cols, vector<int>(rows, 0));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }

    matrix = result;
}