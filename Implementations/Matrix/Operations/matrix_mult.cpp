#include <iostream>
#include <vector>

using std::vector;

/*
Matrix multiplication involves multiplying two matrices A and B to produce a resultant matrix C.
This operation is defined when the number of columns in A matches the number of rows in B.
*/

/*
The steps of the algorithm are as follows:
    - Initialize a resultant matrix C with dimensions m x p.
    - For each element C[i][j] in the resultant matrix, calculate the dot product of the ith row of A and the jth column of B.
    - Store the result in C[i][j].

    Time complexity: O(n^3)
*/
void multiplyMatrices(int A[][2], int B[][2], int C[][2], int m, int n, int p) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            C[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {          
        for (int j = 0; j < p; j++) {       
            for (int k = 0; k < n; k++) {   
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}


