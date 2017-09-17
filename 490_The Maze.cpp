// There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

// Given the ball's start position, the destination and the maze, determine whether the ball could stop at the destination.

// The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space. You may assume that the borders of the maze are all walls. The start and destination coordinates are represented by row and column indexes.

// Example 1

// Input 1: a maze represented by a 2D array

// 0 0 1 0 0
// 0 0 0 0 0
// 0 0 0 1 0
// 1 1 0 1 1
// 0 0 0 0 0

// Input 2: start coordinate (rowStart, colStart) = (0, 4)
// Input 3: destination coordinate (rowDest, colDest) = (4, 4)

// Output: true
// Explanation: One possible way is : left -> down -> left -> down -> right -> down -> right.

// 用BFS做可以知道最小的步数
class Solution { // DFS
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        row = maze.size();  col = maze[0].size();
        target_i = destination[0];  target_j = destination[1];
        return dfs(maze, start[0], start[1]);
    }
    
    bool dfs(vector<vector<int> >& maze, int i, int j) {
        maze[i][j] = -1;  // mark as visited
        for (int k = 0; k < 4; ++k) {
            int ii = i + di[k], jj = j + dj[k];
            while (ii >= 0 && ii < row && jj >= 0 && jj < col && maze[ii][jj] != 1) {
                ii += di[k];  jj += dj[k];
            }
            ii -= di[k];  jj -= dj[k];
            if (maze[ii][jj] == -1)  continue;  // visited
            if (ii == target_i && jj == target_j)  return true;  // find target
            if (dfs(maze, ii, jj))  return true;
        }
        return false;
    }

private:
    int row, col;
    int target_i, target_j;
    int di[4] = {0, 0, 1, -1};
    int dj[4] = {1, -1, 0, 0};
};

class Solution {  // BFS
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int row = maze.size(), col = maze[0].size();
        int dir[5] = {0, 1, 0, -1, 0};
        queue<pair<int, int> > nodes;
        nodes.push(make_pair(start[0], start[1]));
        while (!nodes.empty()) {
            auto p = nodes.front();  nodes.pop();
            maze[p.first][p.second] = -1;  // mark as visited
            for (int k = 0; k < 4; ++k) {
                int i = p.first + dir[k], j = p.second + dir[k + 1];
                while (i >= 0 && i < row && j >= 0 && j < col && maze[i][j] != 1) {
                    i += dir[k];  j += dir[k + 1];
                }
                i -= dir[k];  j -= dir[k + 1];
                if (maze[i][j] == -1)  continue;  // already visited
                if (i == destination[0] && j == destination[1])  return true;
                nodes.push(make_pair(i, j));
            }
        }
        return false;
    }
};