#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

/*
The sum operation in a matrix can involve:
    - Summing All Elements: Adding all the elements in the matrix.
    - Matrix Addition: Adding two matrices element by element.
*/

/*
The steps of the algorithm are as follows:
    - Summing All Elements: Iterate through all the elements in the matrix and add them.
    - Matrix Addition: Iterate through all the elements in the matrices and add them.

    Time Complexity: O(rows * cols)
*/
int sumAllElements(int rows, int cols, int matrix[][3]) {
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

/*
The steps of the algorithm are as follows:
    - Matrix Addition: Iterate through all the elements in the matrices and add them.

    Time Complexity: O(rows * cols)
*/
void addMatrices(int rows, int cols, int matrix1[][2], int matrix2[][2], int result[][2]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

