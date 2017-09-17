class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        board = vector<string>(n, string(n, '.'));
        vector<bool> col(n), plus(2 * n), minus(2 * n);
        int count = 0;
        dfs(col, plus, minus, 0, count, n);
        return ans;
    }
    
    void dfs(vector<bool> &col, vector<bool> &plus, vector<bool> &minus, int i, int &count, int &n) {
        if (i == n) {
            ans.push_back(board);  return;
        }
        for (int j = 0; j < n; ++j) {
            if (!col[j] && !plus[i + j] && !minus[i - j + n]) {
                board[i][j] = 'Q';
                col[j] = true;  plus[i + j] = true;  minus[i - j + n] = true;
                dfs(col, plus, minus, i + 1, count, n);
                col[j] = false;  plus[i + j] = false;  minus[i - j + n] = false;
                board[i][j] = '.';
            }
        }
    }

private:
    vector<vector<string> > ans;
    vector<string> board;
};