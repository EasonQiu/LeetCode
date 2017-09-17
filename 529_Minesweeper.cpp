// Let's play the minesweeper game (Wikipedia, online game)!

// You are given a 2D char matrix representing the game board. 'M' represents an unrevealed mine, 'E' represents an unrevealed empty square, 'B' represents a revealed blank square that has no adjacent (above, below, left, right, and all 4 diagonals) mines, digit ('1' to '8') represents how many mines are adjacent to this revealed square, and finally 'X' represents a revealed mine.

// Now given the next click position (row and column indices) among all the unrevealed squares ('M' or 'E'), return the board after revealing this position according to the following rules:

// If a mine ('M') is revealed, then the game is over - change it to 'X'.
// If an empty square ('E') with no adjacent mines is revealed, then change it to revealed blank ('B') and all of its adjacent unrevealed squares should be revealed recursively.
// If an empty square ('E') with at least one adjacent mine is revealed, then change it to a digit ('1' to '8') representing the number of adjacent mines.
// Return the board when no more squares will be revealed.


class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';  
            return board;
        }
        row = board.size();  col = board[0].size();
        dfs(board, click[0], click[1]);
        return board;
    }
    
    void dfs(vector<vector<char> > &board, int i, int j) {
        // base cases
        if (i < 0 || i >= row || j < 0 || j >= col)  return;
        if (board[i][j] != 'E')  return;
        // count the mines around
        int mines = 0;
        for (int k = 0; k < 8; ++k) {
            int ii = i + di[k],  jj = j + dj[k];
            if (ii >= 0 && ii < row && jj >= 0 && jj < col && board[ii][jj] == 'M') {
                ++mines;
            }
        }
        // go to the next steps
        if (mines == 0) {
            board[i][j] = 'B';
            for (int k = 0; k < 8; ++k)  dfs(board, i + di[k], j + dj[k]);
        } else {
            board[i][j] = '0' + mines;
        }
    }
    
private:
    int row, col;
    int di[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dj[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
};