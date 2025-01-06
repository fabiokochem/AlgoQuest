#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

/*
A 2D matrix in programming is essentially a grid-like data structure organized into rows and columns. 
In C++, it can be implemented using arrays or standard library containers like std::vector.
*/

// It can be implemented using a 2D array, the first [] indicates the number of rows and the second [] indicates the number of columns.
int main(){
    int matrix[4][4];

    matrix[0][0] = 1;

    cout << matrix[0][0] << endl;

    return 0;
}

// It can also be implemented using a vector of vectors, where each vector represents a row in the matrix.
int dynamicMatrix(){
    int rows = 4, cols = 4;
    vector<vector<int>> matrix(rows, vector<int>(cols));

    matrix[0][0] = 1;

    cout << matrix[0][0] << endl;

    return 0;
}

