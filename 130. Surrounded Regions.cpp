#include <iostream>
#include <vector>
using namespace std;

/* 思路是将所有在边上的O，全部链接到一个同一个dummy root下。然后，每次都将
   O与它相邻的O点Union一下。最后遍历所有节点之后，所有与dummy root相连的点
   为最终图中含有的O点。
*/

class Solution {
public:
	void solve(vector<vector<char>>& board) {
		if (board.size() == 0)  return;
		int n = board.size(), m = board[0].size();
		// init the root array, set itself as its root
		root = new int[n * m + 1];
		for (int i = 0; i < n * m + 1; ++i) {
			root[i] = i;
		}
		// union the O regions with their neighbors
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (i == 0 || j == 0) {
					if (board[i][j] == 'O')       unions(i * m + j, n * m);
				} else if (board[i][j] == 'O') {
					if (board[i - 1][j] == 'O')   unions(i * m + j, (i - 1) * m + j);
					if (board[i][j - 1] == 'O')   unions(i * m + j, i * m + j - 1);
					if (i == n - 1 || j == m - 1) unions(i * m + j, n * m);
				}
			}
		}
		// modify the regions that are surrounded by X
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (finds(i * m + j) != finds(n * m))  board[i][j] = 'X';
			}
		}
	}

private:
	int *root;

	int finds(int p) {
		while (p != root[p]) {
			root[p] = root[root[p]];
			p = root[p];
		}
		return p;
	}

	void unions(int p1, int p2) {
		root[finds(p1)] = finds(p2);
	}
};

int main() {
	vector<vector<char> > board(5, vector<char>(5, 'X'));
	board[0][0] = board[0][3] = board[1][1] = board[1][2] = 'O';
	board[1][4] = board[2][1] = board[2][3] = board[3][0] = 'O';
	board[3][2] = board[3][3] = board[3][4] = board[4][2] = 'O';
	board[4][4] = 'O';

	Solution s;
	s.solve(board);

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			cout << board[i][j];
		}
		cout << endl;
	}
	return 0;
}