// You want to build a house on an empty land which reaches all buildings in the shortest amount of distance. You can only move up, down, left and right. You are given a 2D grid of values 0, 1 or 2, where:

// Each 0 marks an empty land which you can pass by freely.
// Each 1 marks a building which you cannot pass through.
// Each 2 marks an obstacle which you cannot pass through.
// For example, given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2):

// 1 - 0 - 2 - 0 - 1
// |   |   |   |   |
// 0 - 0 - 0 - 0 - 0
// |   |   |   |   |
// 0 - 0 - 1 - 0 - 0
// The point (1,2) is an ideal empty land to build a house, as the total travel distance of 3+3+1=7 is minimal. So return 7.

// grid数组里用-n去表明之前有n个buildings可以到达
// 如果之前到达数小于n则之后不用遍历这个节点, 因为从这个节点出发必然无法到达所有节点，与这个节点联通的所有节点必然不会是最终节点！
class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        row = grid.size(), col = grid[0].size();
        vector<vector<int> > distance(row, vector<int>(col)); // sum of distance to buildings
        buildings_count = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] != 1)  continue;
                addDistance(grid, i, j, distance);
                ++buildings_count;
            }
        }
        int min_distance = INT_MAX;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] != -buildings_count)  continue;
                min_distance = min(min_distance, distance[i][j]);
            }
        }
        if (min_distance == INT_MAX || min_distance == 0)  return -1;
        return min_distance;
    }
    
    void addDistance(vector<vector<int> > &grid, int i, int j, vector<vector<int> > &distance) {
        queue<pair<int, int> > que; // for BFS
        que.emplace(i, j);
        int steps = 1;
        while (!que.empty()) {
            int size = que.size();
            for (int k = 0; k < size; ++k) {
                pair<int, int> curr = que.front();  que.pop();
                for (int m = 0; m < 4; ++m) {
                    int ii = curr.first + di[m], jj = curr.second + dj[m];
                    if (ii >= 0 && ii < row && jj >= 0 && jj < col && grid[ii][jj] == -buildings_count) {
                        distance[ii][jj] += steps;
                        que.push(make_pair(ii, jj));
                        --grid[ii][jj];
                    }
                }
            }
            ++steps;
        }
    }
    
private:
    int row, col, buildings_count;
    int di[4] = {0, 0, 1, -1};
    int dj[4] = {1, -1, 0, 0};
};