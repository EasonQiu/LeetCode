// A 2d grid map of m rows and n columns is initially filled with water. We may perform an addLand operation which turns the water at position (row, col) into a land. Given a list of positions to operate, count the number of islands after each addLand operation. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

// Example:
// Given m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]].

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        if (positions.empty())  return vector<int>();
        vector<int> ans(positions.size());
        int count = 0;
        parent = vector<int>(m * n, -1);
        int di[4] = {0, 0, 1, -1};
        int dj[4] = {1, -1, 0, 0};
        for (int ix = 0; ix < positions.size(); ++ix) {
            int i = positions[ix].first, j = positions[ix].second;
            if (parent[i * n + j] != -1)  continue; // duplicates
            // set itself as its parent
            parent[i * n + j] = i * n + j;
            ++count;
            // unions itself with its neighbors
            for (int k = 0; k < 4; ++k) {
                int ii = i + di[k], jj = j + dj[k];
                if (ii < 0 || ii == m || jj < 0 || jj == n || parent[ii * n + jj] == -1)  continue;
                if (finds(i * n + j) != finds(ii * n + jj)) {
                    unions(i * n + j, ii * n + jj);
                    --count;
                }
            }
            // save the result
            ans[ix] = count;
        }
        return ans;
    }
    
    int finds(int i) {
        while (i != parent[i]) {
            parent[i] = parent[parent[i]]; // path compression
            i = parent[i];
        }
        return i;
    }
    
    void unions(int i, int j) {
        parent[finds(i)] = finds(j);
    }
    
private:
    vector<int> parent;
};