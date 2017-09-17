// There is an m by n grid with a ball. Given the start coordinate (i,j) of the ball, 
// you can move the ball to adjacent cell or cross the grid boundary in four directions 
// (up, down, left, right). However, you can at most move N times. Find out the number of 
// paths to move the ball out of grid boundary. The answer may be very large, return it after 
// mod 109 + 7.

// Example 1:
// Input:m = 2, n = 2, N = 2, i = 0, j = 0
// Output: 6
// Explanation:

// Example 2:
// Input:m = 1, n = 3, N = 3, i = 0, j = 1
// Output: 12
// Explanation:

// Note:
// Once you move the ball out of boundary, you cannot move it back.
// The length and height of the grid is in range [1,50].
// N is in range [0,50].

// DP
// opt[i][j][k] = sum(opt[i - 1][j][k - 1], opt[i][j - 1][k - 1],
// 										opt[i + 1][j][k - 1], opt[i][j + 1][k - 1])
// 感想：We can also reduce the memory usage by using two grids instead of N, 
// as we only need to look one step back. We can use N % 2 and (N + 1) % 2 to alternate grids 
// so we do not have to copy.
class Solution {
 public:
  int findPaths(int m, int n, int N, int i, int j) {
  	vector<vector<vector<long> > > opt(m, vector<vector<long> >(n, vector<long>(N + 1)));
  	for (int k = 1; k <= N; ++k) {
  		for (int i = 0; i < m; ++i) {
  			for (int j = 0; j < n; ++j) {
  				opt[i][j][k] = (i == 0     ? 1 : opt[i - 1][j][k - 1]) +
  											 (i == m - 1 ? 1 : opt[i + 1][j][k - 1]) +
  											 (j == 0     ? 1 : opt[i][j - 1][k - 1]) +
  											 (j == n - 1 ? 1 : opt[i][j + 1][k - 1]);
  				opt[i][j][k] = opt[i][j][k] % 1000000007;
  			}
  		}
  	}
  	return opt[i][j][N];
  }
};

// DFS + memorization, TLE
class Solution {
 public:
  int findPaths(int m, int n, int N, int i, int j) {
  	vector<vector<vector<long> > > mem(m, vector<vector<long> >(n, vector<long>(N + 1)));
  	m_ = m;  n_ = n;  N_ = N;
  	return dfs(i, j, N, mem);
  }

  int dfs(int i, int j, int steps, vector<vector<vector<long> > > &mem) {
  	// base case
  	if (i == -1 || i == m_ || j == -1 || j == n_)  return 1;
  	if (steps == 0)  return 0;
  	if (mem[i][j][steps] != 0)  return mem[i][j][steps];
  	// normal case
  	for (int k = 0; k < 4; ++k) {
  		mem[i][j][steps] += dfs(i + di[k], j + dj[k], steps - 1, mem);
  	}
  	mem[i][j][steps] = mem[i][j][steps] % 1000000007;
  	// return value
  	return mem[i][j][steps];
  }

 private:
 	int m_, n_, N_;
 	int di[4] = {-1, 0, 1, 0};
 	int dj[4] = {0, -1, 0, 1};
};