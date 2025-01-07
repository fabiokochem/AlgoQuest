#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

/*
When we look into a matrix diagonal, we can have two types of diagonals:
    - Principal Diagonal: The diagonal that goes from the top-left corner to the bottom-right corner.
    - Secondary Diagonal: The diagonal that goes from the top-right corner to the bottom-left corner.

From this, we can use the extraction of the diagonals to solve some problems.
*/

/*
This function extracts the principal diagonal of a matrix.
The steps for this algorithm are as follows:
    - Create a vector to store the principal diagonal.
    - Iterate over the rows of the matrix.
    - For each row, get the element at the row index and column index.
    - Add the element to the principal diagonal vector.
    - Return the principal diagonal vector.

Time Complexity: O(n)
*/
vector<int> main_diagonal(vector<vector<int>> &matrix){
    vector<int> main_diagonal;
    for(int i = 0; i < matrix.size(); i++){
        main_diagonal.push_back(matrix[i][i]);
    }
    return main_diagonal;
}


/*
This function extracts the secondary diagonal of a matrix.
The steps for this algorithm are asa follows:
    - Create a vector to store the secondary diagonal.
    - Iterate over the rows of the matrix.
    - For each row, get the element at the row index and the column index that is the size of the matrix minus the row index minus 1.
    - Add the element to the secondary diagonal vector.
    - Return the secondary diagonal vector.

Time Complexity: O(n)
*/
vector<int> secondary_diagonal(vector<vector<int>> &matrix){
    vector<int> secondary_diagonal;
    for(int i = 0; i < matrix.size(); i++){
        secondary_diagonal.push_back(matrix[i][matrix.size() - i - 1]);
    }
    return secondary_diagonal;
}


int main(){
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<int> main_diagonal_result = main_diagonal(matrix);
    vector<int> secondary_diagonal_result = secondary_diagonal(matrix);

    cout << "Main Diagonal: ";
    for(int i = 0; i < main_diagonal_result.size(); i++){
        cout << main_diagonal_result[i] << " ";
    }

    cout << "Secondary Diagonal: ";
    for(int i = 0; i < secondary_diagonal_result.size(); i++){
        cout << secondary_diagonal_result[i] << " ";
    }

    return 0;
}