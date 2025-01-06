#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

/*
The sub operation in a matrix can involve:
    - Subtracting All Elements: Subtracting all the elements in the matrix.
    - Matrix Subtraction: Subtracting two matrices element by element.
*/

/*
The steps of the algorithm are as follows:
    - Subtracting All Elements: Iterate through all the elements in the matrix and subtract them.
    - Matrix Subtraction: Iterate through all the elements in the matrices and subtract them.

    Time Complexity: O(rows * cols)
*/
int subAllElements(int rows, int cols, int matrix[][3]) {
    int sub = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sub -= matrix[i][j];
        }
    }
    return sub;
}

/*
The steps of the algorithm are as follows:
    - Matrix Subtraction: Iterate through all the elements in the matrices and subtract them.

    Time Complexity: O(rows * cols)
*/
void subMatrices(int rows, int cols, int matrix1[][2], int matrix2[][2], int result[][2]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}
