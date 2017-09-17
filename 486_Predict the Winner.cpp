// Given an array of scores that are non-negative integers. Player 1 picks one of the numbers 
// from either end of the array followed by the player 2 and then player 1 and so on. Each time 
// a player picks a number, that number will not be available for the next player. This continues 
// until all the scores have been chosen. The player with the maximum score wins.

// Given an array of scores, predict whether player 1 is the winner. You can assume each player 
// plays to maximize his score.

// Example 1:
// Input: [1, 5, 2]
// Output: False
// Explanation: Initially, player 1 can choose between 1 and 2. 
// If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5, 
// then player 1 will be left with 1 (or 2). 
// So, final score of player 1 is 1 + 2 = 3, and player 2 is 5. 
// Hence, player 1 will never be the winner and you need to return False.

// Example 2:
// Input: [1, 5, 233, 7]
// Output: True
// Explanation: Player 1 first chooses 1. Then player 2 have to choose between 5 and 7. No matter 
// which number player 2 choose, player 1 can choose 233.
// Finally, player 1 has more score (234) than player 2 (12), so you need to return True 
// representing player1 can win.

// Note:
// 1 <= length of the array <= 20.
// Any scores in the given array are non-negative integers and will not exceed 10,000,000.
// If the scores of both players are equal, then player 1 is still the winner.

// 感想：在处理recursion的base case的时候，最好先进入function再检测变量有效性，不要在进入之前检测
//      当我选择nums[i]时，后面我有两种可能获得的最大值，但是对手一定会最大化他的得分，也就是最小化我可能的得分
//      所以递推中有min的存在。
//      minmax problem!!

class Solution {
 public:
  bool PredictTheWinner(vector<int>& nums) {
  	if (nums.size() <= 1)  return true;
  	int target = (accumulate(nums.begin(), nums.end(), 0) + 1) / 2;
  	mem = vector<vector<int> >(nums.size(), vector<int>(nums.size(), -1));
  	return helper(nums, 0, nums.size() - 1) >= target;
  }

  // return the max score the player will get from nums[i] to nums[j]
  int helper(vector<int> &nums, int i, int j) {
  	if (i > j)  return 0;
  	if (mem[i][j] != -1)  return mem[i][j];
  	int num1 = nums[i] + min(helper(nums, i + 2, j), helper(nums, i + 1, j - 1));
  	int num2 = nums[j] + min(helper(nums, i, j - 2), helper(nums, i + 1, j - 1));
  	mem[i][j] = max(num1, num2);
  	return mem[i][j];
  }

 private:
 	vector<vector<int> > mem;
};