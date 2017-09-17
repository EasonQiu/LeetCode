// Given a 2D board and a word, find if the word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

// For example,
// Given board =

// [
//   ['A','B','C','E'],
//   ['S','F','C','S'],
//   ['A','D','E','E']
// ]
// word = "ABCCED", -> returns true,
// word = "SEE", -> returns true,
// word = "ABCB", -> returns false.

// 写dfs的时候尽量不要再开一个数组去标记有没有走过，最好是修改原数组
// 写递归的时候，一些边界情况在base case里面写，不要到主程序里面写
class Solution {
public:
  bool exist(vector<vector<char>>& board, string word) {
  	if (board.empty() || word.empty())  return false;
  	for (int i = 0; i < board.size(); ++i) {
  		for (int j = 0; j < board[0].size(); ++j) {
  			if (dfs(board, word, i, j, 0))  return true;
  		}
  	}
  	return false;
	}

	bool dfs(vector<vector<char> > &board, string &word, int i, int j, int index) {
		if (index == word.size())  return true;
		if (i < 0 || i == board.size() || j < 0 || j == board[0].size())  return false;
		if (board[i][j] == '\0' || board[i][j] != word[index])  return false;
		char cache = board[i][j];  
		board[i][j] = '\0';
		if (dfs(board, word, i, j - 1, index + 1) || dfs(board, word, i, j + 1, index + 1) ||
			  dfs(board, word, i - 1, j, index + 1) || dfs(board, word, i + 1, j, index + 1)) {
			return true;
		}
		board[i][j] = cache;
		return false;
	}
};