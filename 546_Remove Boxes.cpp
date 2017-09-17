// Given several boxes with different colors represented by different positive numbers. 
// You may experience several rounds to remove boxes until there is no box left. 
// Each time you can choose some continuous boxes with the same color (composed of k boxes, 
// k >= 1), remove them and get k*k points.
// Find the maximum points you can get.

// Example 1:
// Input:
// [1, 3, 2, 2, 2, 3, 4, 3, 1]
// Output:
// 23
// Explanation:
// [1, 3, 2, 2, 2, 3, 4, 3, 1] 
// ----> [1, 3, 3, 4, 3, 1] (3*3=9 points) 
// ----> [1, 3, 3, 3, 1] (1*1=1 points) 
// ----> [1, 1] (3*3=9 points) 
// ----> [] (2*2=4 points)
// Note: The number of boxes n would not exceed 100.

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// DP
// memo[l][r][k], the largest number we can get using lth to rth (inclusive) boxes with 
// k same colored boxes as rth box appended at the end.
// 注意int[]在传参时的写法
class Solution {
public:
  int removeBoxes(vector<int>& boxes) {
  	int size = boxes.size();
  	int dp[100][100][100] = {};
  	return dfs(boxes, dp, 0, size - 1, 0);
  }

  int dfs(vector<int> &boxes, int dp[100][100][100], int l, int r, int k) {
  	if (l > r)  return 0;
  	if (dp[l][r][k] != 0)  return dp[l][r][k];
  	while (l < r && boxes[r - 1] == boxes[r]) {
  		--r;  ++k;
  	}
  	dp[l][r][k] = dfs(boxes, dp, l, r - 1, 0) + (k + 1) * (k + 1);
  	for (int i = l; i < r; ++i) {
  		if (boxes[i] != boxes[r])  continue;
  		dp[l][r][k] = max(dp[l][r][k], dfs(boxes, dp, l, i, k + 1) + dfs(boxes, dp, i + 1, r - 1, 0));
  	}
  	return dp[l][r][k];
  }
};

// 加memorization的递归可能会存在unnecessary computations (not recomputations).
// DFS + memorization
class Solution2 {
public:
  int removeBoxes(vector<int>& boxes) {
  	int size = boxes.size();
  	if (size == 0)  return 0;
  	string used(size, '0');
  	unordered_map<string, int> mem;
  	return dfs(boxes, used, mem, size);
  }

  int dfs(vector<int> &boxes, string &used, unordered_map<string, int> &mem, int leftover) {
  	// base case
  	if (leftover == 0)  return 0;
  	if (mem.find(used) != mem.end())  return mem[used];
  	// normal case
  	int max_points = 0, j, k;
  	string used2;
  	for (int i = 0; i < used.size(); ++i) {
  		if (used[i] == '1')  continue;
  		// find the other boxes needed to be removed, calculate k
  		k = 1;  j = i + 1;
  		used2 = used;  used2[i] = '1';
  		while (j < used.size()) {
  			if (used2[j] == '1') {
  				++j;
  			} else {
  				if (boxes[j] != boxes[i])  break;
  				used2[j++] = '1';  ++k;
  			}
  		}
  		i = --j;
  		// go to the next step
  		max_points = max(max_points, k * k + dfs(boxes, used2, mem, leftover - k));
  	}
  	// update mem
  	mem[used] = max_points;
  	return max_points;
  }
};

int main() {
	vector<int> boxes = {1, 3, 2, 2, 2, 3, 4, 3, 1};
	Solution sol;
	cout << sol.removeBoxes(boxes) << endl;
}