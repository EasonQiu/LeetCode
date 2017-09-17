// You are given a m x n 2D grid initialized with these three possible values.

// -1 - A wall or an obstacle.
// 0 - A gate.
// INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
// Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

// For example, given the 2D grid:
// INF  -1  0  INF
// INF INF INF  -1
// INF  -1 INF  -1
//   0  -1 INF INF
// After running your function, the 2D grid should be:
//   3  -1   0   1
//   2   2   1  -1
//   1  -1   2  -1
//   0  -1   3   4

// BFS
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.empty())  return;
        int row = rooms.size(), col = rooms[0].size();
        queue<pair<int, int> > queue;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (rooms[i][j] == 0)  queue.push(make_pair(i, j));
            }
        }
        int steps = 0;
        int di[4] = {0, 0, 1, -1};
        int dj[4] = {1, -1, 0, 0};
        while (!queue.empty()) {
            int size = queue.size();
            for (int k = 0; k < size; ++k) {
                // get the front element from queue
                int i = queue.front().first, j = queue.front().second;
                queue.pop();
                // update the current node
                if (rooms[i][j] != 0 && rooms[i][j] != INT_MAX)  continue;
                rooms[i][j] = steps;
                // check its neighborhoods
                for (int m = 0; m < 4; ++m) {
                    int ii = i + di[m], jj = j + dj[m];
                    if (ii >= 0 && ii < row && jj >= 0 && jj < col && rooms[ii][jj] == INT_MAX) {
                        queue.push(make_pair(ii, jj));
                    }
                }
            }
            ++steps;
        }
    }
};


// DFS
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.empty())  return;
        row = rooms.size(), col = rooms[0].size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (rooms[i][j] != 0)  continue;
                dfs(rooms, i, j, 0);
            }
        }
    }
    
    void dfs(vector<vector<int> > &rooms, int i, int j, int steps) {
        if (i < 0 || i == row || j < 0 || j == col)  return;
        if (rooms[i][j] == -1)  return;
        if (steps > rooms[i][j])  return; // ensure it will not go back
        rooms[i][j] = steps;
        dfs(rooms, i + 1, j, steps + 1);
        dfs(rooms, i - 1, j, steps + 1);
        dfs(rooms, i, j + 1, steps + 1);
        dfs(rooms, i, j - 1, steps + 1);
    }

private:
    int row, col;
};