// We are playing the Guess Game. The game is as follows:
// I pick a number from 1 to n. You have to guess which number I picked.
// Every time you guess wrong, I'll tell you whether the number I picked is higher or lower.

// However, when you guess a particular number x, and you guess wrong, you pay $x. You win 
// the game when you guess the number I picked.

// Example:
// n = 10, I pick 8.
// First round:  You guess 5, I tell you that it's higher. You pay $5.
// Second round: You guess 7, I tell you that it's higher. You pay $7.
// Third round:  You guess 9, I tell you that it's lower. You pay $9.
// Game over. 8 is the number I picked.
// You end up paying $5 + $7 + $9 = $21.

// Given a particular n ≥ 1, find out how much money you need to have to guarantee a win.

// 解法：For each number x in range[i~j]
// we do: result_when_pick_x = x + max{DP([i~x-1]), DP([x+1, j])}
// --> // the max means whenever you choose a number, the feedback is always bad and therefore leads you to a worse branch.
// then we get DP([i~j]) = min{xi, ... ,xj}
// --> // this min makes sure that you are minimizing your cost.

class Solution {
public:
  int getMoneyAmount(int n) {
  	vector<vector<int> > opt(n + 1, vector<int>(n + 1));
  	return dp(opt, 1, n);
  }

  int dp(vector<vector<int> > &opt, int left, int right) {
  	if (left >= right)  return 0;
  	if (opt[left][right] != 0)  return opt[left][right];
  	int min_pay = INT_MAX, cur_pay;
  	for (int i = left; i <= right; ++i) {
  		cur_pay = i + max(dp(opt, left, i - 1), dp(opt, i + 1, right));
  		min_pay = min(min_pay, cur_pay);
  	}
  	opt[left][right] = min_pay;
  	return min_pay;
  }
};