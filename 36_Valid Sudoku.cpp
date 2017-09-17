// Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

// The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

// Note:
// A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells 
// need to be validated.

// 可以不用hashset用array就可以解决
class Solution {
public:
  bool isValidSudoku(vector<vector<char>>& board) {
  	unordered_set<int> init_nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  	vector<unordered_set<int> > rows(9, init_nums), cols(9, init_nums), blocks(9, init_nums);
  	for (int i = 0; i < 9; ++i) {
  		for (int j = 0; j < 9; ++j) {
  			if (board[i][j] == '.')  continue;
  			int val = board[i][j] - '0';
  			if (rows[i].erase(val) == 0)  return false;
  			if (cols[j].erase(val) == 0)  return false;
  			if (blocks[3 * (i / 3) + (j / 3)].erase(val) == 0)  return false;
  		}
  	}
  	return true;
  }
};
