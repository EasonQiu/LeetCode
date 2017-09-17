// Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
// A region is captured by flipping all 'O's into 'X's in that surrounded region.

// For example,
// X X X X
// X O O X
// X X O X
// X O X X
// After running your function, the board should be:
// X X X X
// X X X X
// X X X X
// X O X X

// 解法：思路是将所有在边上的O，全部链接到一个同一个dummy root下。然后，每次都将
// O与它相邻的O点Union一下。最后遍历所有节点之后，所有与dummy root相连的点
// 为最终图中含有的O点。

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  void solve(vector<vector<char>>& board) {
    if (board.size() == 0 || board[0].size() == 0)  return;
    int row = board.size(), col = board[0].size();
    // init the root array, set itself as its root
    parent = new int[row * col + 1];
    for (int i = 0; i < row * col + 1; ++i)  parent[i] = i;
    // union the O regions with their neighbors
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        if (board[i][j] == 'X')  continue;
        if (i == 0 || i == row - 1 || j == 0 || j == col - 1)  unions(i * col + j, row * col);
        if (i + 1 < row && board[i + 1][j] == 'O')  unions(i * col + j, (i + 1) * col + j);
        if (j + 1 < col && board[i][j + 1] == 'O')  unions(i * col + j, i * col + (j + 1));
      }
    }
    // modify the regions that are surrounded by X
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        if (find(i * col + j) != find(row * col))  board[i][j] = 'X';
      }
    }
  }

  void unions(int index1, int index2) {
    parent[find(index1)] = find(index2);
  }

  int find(int index) {
    while (parent[index] != index) {
      parent[index] = parent[parent[index]];
      index = parent[index];
    }
    return index;
  }

private:
  int *parent;
};

class Solution2 { // dfs
public:
    void solve(vector<vector<char>>& board) {
    	int row, col;
    	// check corner cases
    	if (!board.empty() && !board[0].empty()) {
    		row = board.size();  col = board[0].size();
    	} else {
    		return;
    	}
    	// search the bound in board, and make changes in board2
        vector<vector<char> > board2(row, vector<char>(col, 'X'));
        for (int j = 0; j < col; ++j) {
        	if (board[0][j] == 'O')  dfs(board, board2, 0, j, row, col);
        	if (board[row-1][j] == 'O')  dfs(board, board2, row-1, j, row, col);
        }
        for (int i = 0; i < row; ++i) {
        	if (board[i][0] == 'O')  dfs(board, board2, i, 0, row, col);
        	if (board[i][col-1] == 'O')  dfs(board, board2, i, col-1, row, col);
        }
        // copy the result in board2 to board
        for (int i = 0; i < row; ++i) {
        	for (int j = 0; j < col; ++j) {
        		board[i][j] = board2[i][j];
        	}
        }
        return;
    }

    void dfs(vector<vector<char> >& board, vector<vector<char> >& board2,
    		 int i, int j, int& row, int& col) {
    	board[i][j] = 'X';  board2[i][j] = 'O';
    	// search in four directions
    	int di[4] = {0, 0, -1, 1};
    	int dj[4] = {1, -1, 0, 0};
    	for (int k = 0; k < 4; ++k) {
    		if (i + di[k] >= 0 && i + di[k] < row
    		 && j + dj[k] >= 0 && j + dj[k] < col
    		 && board[i + di[k]][j + dj[k]] == 'O') {
    			dfs(board, board2, i + di[k], j + dj[k], row, col);
    		}
    	}
    }

    void bfs(vector<vector<char> >& board, vector<vector<char> >& board2,
    		 int i, int j, int& row, int& col) {
    	queue<pair<int, int> > levelPoints;
    	levelPoints.push(make_pair(i, j));
    	while (!levelPoints.empty()) {
    		int size = levelPoints.size();
    		for (int n = 0; n < size; ++n) {
    			i = levelPoints.front().first;
    			j = levelPoints.front().second;
    			levelPoints.pop();
    			board[i][j] = 'X';  board2[i][j] = 'O';
    			// search in four directions
    			int di[4] = {0, 0, -1, 1};
    			int dj[4] = {1, -1, 0, 0};
    			for (int k = 0; k < 4; ++k) {
    				if (i + di[k] >= 0 && i + di[k] < row
    		 		 && j + dj[k] >= 0 && j + dj[k] < col
    		 		 && board[i + di[k]][j + dj[k]] == 'O') {
    					levelPoints.push(make_pair(i + di[k], j + dj[k]));
    				}
    			}
    		}
    	}
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