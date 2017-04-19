class Solution {
public:
    // DFS version
    int islandPerimeter(vector<vector<int> >& grid) {
        if (grid.empty())  return 0;
        int ix = INT_MAX, jx = INT_MAX, answer = 0;  bool flag = false;
        // init the 2-D array to mark the foot steps
        vector<vector<bool> > foot(grid.size(), vector<bool>(grid[0].size(), true));
        // find the first island
        for (int i = 0; !flag && i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1)  {
                    ix = i;  jx = j;  flag = true;  break;
                }
            }
        }
        if (ix == INT_MAX && jx == INT_MAX)  return 0;
        dfs(grid, foot, answer, ix, jx);
        return answer;
    }
    
    void dfs(vector<vector<int> >& grid, vector<vector<bool> >& foot, int& answer, int i, int j) {
        answer += 4;  foot[i][j] = false;
        if (i - 1 >= 0 && grid[i-1][j] == 1) {
            --answer;
            if (foot[i-1][j])  dfs(grid, foot, answer, i-1, j);
        }
        if (i + 1 < grid.size() && grid[i+1][j] == 1) {
            --answer;
            if (foot[i+1][j])  dfs(grid, foot, answer, i+1, j);
        }
        if (j - 1 >= 0 && grid[i][j-1] == 1) {
            --answer;
            if (foot[i][j-1])  dfs(grid, foot, answer, i, j-1);
        }
        if (j + 1 < grid[0].size() && grid[i][j+1] == 1) {
            --answer;
            if (foot[i][j+1])  dfs(grid, foot, answer, i, j+1);
        }
    }
    
    // simple O(N^2) version, beats 14.2%
    int islandPerimeter2(vector<vector<int>>& grid) {
        if (grid.empty())  return 0;
        int answer = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 0)  continue;
                answer += 4;
                if (i - 1 >= 0 && grid[i-1][j] == 1)  --answer;
                if (i + 1 < grid.size() && grid[i+1][j] == 1)  --answer;
                if (j - 1 >= 0 && grid[i][j-1] == 1)  --answer;
                if (j + 1 < grid[0].size() && grid[i][j+1] == 1)  --answer;
            }
        }
        return answer;
    }
};