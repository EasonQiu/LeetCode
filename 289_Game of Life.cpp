#include <iostream>
#include <vector>
using namespace std;

// 可以用2 bits来同时存储current和next的状态
// 例如：10表示从dead到live

class Solution {
public:
    int numNeighbors(const vector<vector<int>>& board, int bi, int bj){
        int sum = 0;
        if (bi - 1 >= 0 && bj - 1 >= 0) sum += board[bi-1][bj-1];
        if (bi - 1 >= 0 && bj >= 0) sum += board[bi-1][bj];
        if (bi - 1 >= 0 && bj + 1 < board[bi].size()) sum += board[bi-1][bj+1];
        if (bi >= 0 && bj - 1 >= 0) sum += board[bi][bj-1];
        if (bi >= 0 && bj + 1 < board[bi].size()) sum += board[bi][bj+1];
        if (bi + 1 < board.size() && bj - 1 >= 0) sum += board[bi+1][bj-1];
        if (bi + 1 < board.size() && bj >= 0) sum += board[bi+1][bj];
        if (bi + 1 < board.size() && bj + 1 < board[bi].size()) sum += board[bi+1][bj+1];
        return sum;
    }

    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> newBoard;
        for (int i = 0; i< board.size(); i++)
            newBoard.push_back(vector<int>(board[i].size()));
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[i].size(); j++){
                if (board[i][j] == 0){
                    if (numNeighbors(board, i, j) == 3)
                        newBoard[i][j] = 1;
                    else
                        newBoard[i][j] = 0;
                }else if (board[i][j] == 1){
                    if (numNeighbors(board, i, j) == 2 || numNeighbors(board, i, j) == 3)
                        newBoard[i][j] = 1;
                    else
                        newBoard[i][j] = 0;
                }
            }
        }
        if (board.size() > 0)  swap(board, newBoard);
    }
};

int main() {
    int a[] = {1,0,0};
    vector<int> oneline(a,a+3);
    vector<vector<int>> board;
    board.push_back(oneline); board.push_back(oneline); board.push_back(oneline);

    Solution s;
    s.gameOfLife(board);

    return 0;
}