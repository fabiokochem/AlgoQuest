#include <iostream>
#include <vector>

using std::vector;

/*
A matrix is simmetric when it is equal to its transpose. In mathematical terms, for a m AA, it is symmetric if:
    A[i][j]=A[j][i]∀ i,j
    A[i][j]=A[j][i]∀i,j

This property is only applicable to square matrices (n×nn×n), as non-square matrices cannot be symmetric.

The steps of this algorithm are as follows:
    - Read the matrix dimensions n×nn×n.
    - Read the matrix elements.
    - Check if the matrix is symmetric.

Time Complexity: O(n^2)
*/
bool isSymmetric(vector<vector<int>> &matrix) {
    int n = matrix.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                return false;
            }
        }
    }
    return true;
}

int main(){
    int n;
    std::cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> matrix[i][j];
        }
    }

    if (isSymmetric(matrix)) {
        std::cout << "The matrix is symmetric\n";
    } else {
        std::cout << "The matrix is not symmetric\n";
    }

    return 0;
}
