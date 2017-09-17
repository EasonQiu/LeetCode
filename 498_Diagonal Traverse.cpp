// Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.

// Example:
// Input:
// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
// Output:  [1,2,4,7,5,3,6,8,9]
// Explanation:

// Note:
// The total number of elements of the given matrix will not exceed 10,000.


class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty())  return vector<int>();
        int row = matrix.size(), col = matrix[0].size();
        vector<int> ans(row * col);
        int dir[2][2] = {{-1, 1}, {1, -1}};  // up-right, down-left
        int move = 0;  // 0 for up-right, 1 for down-left
        int i = 0, j = 0; // index of matrix
        int k = 0;  // index of ans
        while (i != row - 1 || j != col - 1) {
            // iterate the current line
            while (i >= 0 && i < row && j >= 0 && j < col) {
                ans[k++] = matrix[i][j];
                i += dir[move][0];  j += dir[move][1];
            }
            i -= dir[move][0];  j -= dir[move][1];
            // move to the next line & change the direction
            if (move == 0) {
                (j == col - 1) ? i += 1 : j += 1;
            } else {
                (i == row - 1) ? j += 1 : i += 1;
            }
            move = 1 - move;
        }
        ans[k] = matrix[i][j];
        return ans;
    }
};