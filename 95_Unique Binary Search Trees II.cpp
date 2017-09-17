// Given an integer n, generate all structurally unique BST's (binary search trees) that 
// store values 1...n.

// For example,
// Given n = 3, your program should return all 5 unique BST's shown below.

//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3


// dp[i][j] 存储所有[i, j]能构成的trees
// dp[i][j] = {dp[i, k - 1] && dp[k + 1][j]}  if k from [i, j]
class Solution {
public:
  vector<TreeNode*> generateTrees(int n) {
    if (n == 0)  return vector<TreeNode*>();
  	vector<vector<vector<TreeNode*>>> dp(n + 2, vector<vector<TreeNode*>>(n + 2, vector<TreeNode*>()));
  	// base case
  	for (int i = 1; i <= n + 1; ++i) {
  		dp[i][i].push_back(new TreeNode(i));
  		dp[i][i - 1].push_back(NULL);
  	}
  	// fill the array
  	for (int j = 2; j <= n; ++j) {
  		for (int i = j - 1; i >= 1; --i) {
  			for (int k = i; k <= j; ++k) {
  				for (TreeNode* left : dp[i][k - 1]) {
  					for (TreeNode* right : dp[k + 1][j]) {
  						dp[i][j].push_back(new TreeNode(k));
  						dp[i][j].back()->left = left;
  						dp[i][j].back()->right = right;
  					}
  				}
  			}
  		}
  	}
  	// final result
  	return dp[1][n];
  }
};