#include <iostream>

using std::cout;
using std::endl;

/*
Matrix search involves finding a specific element or set of elements in a matrix. 
Depending on the properties of the matrix, the approach and efficiency of the search can vary.
*/

/*
The steps of the algorithm are as follows:
    - Iterate through each element of the matrix.
    - Compare the element with the target value.
    - If the element matches the target, return true.
    - If the entire matrix is traversed without finding the target, return false.

    Time complexity: O(n*m)
*/
bool search(int matrix[][3], int rows, int cols, int target) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == target) {
                cout << "Found at position: (" << i << ", " << j << ")" << endl;
                return true;
            }
        }
    }
    return false;
}
