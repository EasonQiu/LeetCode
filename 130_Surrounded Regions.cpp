#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class Solution {
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
	vector<vector<char> > board(4, vector<char>(4, 'X'));
	board[1][1] = board[1][2] = board[2][2] = board[3][1] = 'O';

	Solution s;
	s.solve(board);

	for (auto row : board) {
		for (char ch : row)  cout << ch << " ";
		cout << endl;
	}
	return 0;
}