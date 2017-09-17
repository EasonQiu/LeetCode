// Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

// For example,
// If n = 4 and k = 2, a solution is:

// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > ans;
        vector<int> comb(k);
        dfs(comb, 0, k, 1, n, ans);
        return ans;
    }
    
    void  dfs(vector<int> &comb, int index, int k, int lower, int n, vector<vector<int> > &ans) {
        if (index == k) {
            ans.push_back(comb);
            return;
        }
        int upper = n - k + index + 1;
        for (int i = lower; i <= upper; ++i) {
            comb[index] = i;
            dfs(comb, index + 1, k, i + 1, n, ans);
        }
    }
};