// Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

// The distance between two adjacent cells is 1.
// Example 1: 
// Input:

// 0 0 0
// 0 1 0
// 0 0 0
// Output:
// 0 0 0
// 0 1 0
// 0 0 0
// Example 2: 
// Input:

// 0 0 0
// 0 1 0
// 1 1 1
// Output:
// 0 0 0
// 0 1 0
// 1 2 1
// Note:
// The number of elements of the given matrix will not exceed 10,000.
// There are at least one 0 in the given matrix.
// The cells are adjacent in only four directions: up, down, left and right.


// General idea is BFS. Some small tricks:
// At beginning, set cell value to Integer.MAX_VALUE if it is not 0.
// If newly calculated distance >= current distance, then we don't need to explore that cell again.
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty())  return vector<vector<int> >();
        int row = matrix.size(),  col = matrix[0].size();
        // matrix[i][j]变成从[i][j]出发至最近的0的最短距离
        queue<pair<int, int> > que;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] == 0) {
                    que.push(make_pair(i, j));
                } else {
                    matrix[i][j] = INT_MAX;
                }
            }
        }
        while (!que.empty()) {
            int i = que.front().first, j = que.front().second;
            que.pop();
            for (int k = 0; k < 4; ++k) {
                int i2 = i + di[k], j2 = j + dj[k];
                if (i2 < 0 || i2 == row || j2 < 0 || j2 == col ||
                    matrix[i][j] + 1 >= matrix[i2][j2])  continue;
                matrix[i2][j2] = matrix[i][j] + 1;
                que.push(make_pair(i2, j2));
            }
        }
        return matrix;
    }
    
private:
    int di[4] = {0, 0, 1, -1};
    int dj[4] = {1, -1, 0, 0};
};