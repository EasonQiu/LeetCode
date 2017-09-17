// Given a 2D grid, each cell is either a wall 'W', an enemy 'E' or empty '0' (the number zero), return the maximum enemies you can kill using one bomb.
// The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since the wall is too strong to be destroyed.
// Note that you can only put the bomb at an empty cell.

// Example:
// For the given grid

// 0 E 0 0
// E 0 W E
// 0 E 0 0

// return 3. (Placing a bomb at (1,1) kills 3 enemies)

class Solution { // similar to Product Except Itself
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty())  return 0;
        int row =  grid.size(), col = grid[0].size();
        int kills[row][col] = {};
        for (int i = 0; i < row; ++i) {
            int left_kill = 0, right_kill = 0;
            for (int left = 0, right = col - 1; left < col; ++left, --right) {
                kills[i][left] += left_kill;
                kills[i][right] += right_kill;
                left_kill = (grid[i][left] == 'W') ? 0 : (grid[i][left] == 'E') ? left_kill + 1 : left_kill;
                right_kill = (grid[i][right] == 'W') ? 0 : (grid[i][right] == 'E') ? right_kill + 1 : right_kill;
            }
        }
        for (int j = 0; j < col; ++j) {
            int up_kill =  0, down_kill = 0;
            for (int up = 0, down = row - 1; up < row; ++up, --down) {
                kills[up][j] += up_kill;
                kills[down][j] += down_kill;
                up_kill = (grid[up][j] == 'W') ? 0 : (grid[up][j] == 'E') ? up_kill + 1 : up_kill;
                down_kill = (grid[down][j] == 'W') ? 0 : (grid[down][j] == 'E') ? down_kill + 1 : down_kill;
            }
        }
        int max_kill = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] != '0')  continue;
                max_kill = max(max_kill, kills[i][j]);
            }
        }
        return max_kill;
    }
};