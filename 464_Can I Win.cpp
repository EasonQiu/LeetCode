// In the "100 game," two players take turns adding, to a running total, any integer 
// from 1..10. The player who first causes the running total to reach or exceed 100 wins.

// What if we change the game so that players cannot re-use integers?

// For example, two players might take turns drawing from a common pool of numbers of 1..15 
// without replacement until they reach a total >= 100.

// Given an integer maxChoosableInteger and another integer desiredTotal, determine if the 
// first player to move can force a win, assuming both players play optimally.

// You can always assume that maxChoosableInteger will not be larger than 20 and desiredTotal 
// will not be larger than 300.

// Example
// Input:
// maxChoosableInteger = 10
// desiredTotal = 11
// Output:
// false

// Explanation:
// No matter which integer the first player choose, the first player will lose.
// The first player can choose an integer from 1 up to 10.
// If the first player choose 1, the second player can only choose integers from 2 up to 10.
// The second player will win by choosing 10 and get a total = 11, which is >= desiredTotal.
// Same with other integers chosen by the first player, the second player will always win.

// 解法：DFS，加memorize保存之前计算过的结论
//      只要能找到有一个选择能稳赢就是true，所有选择都会输就是false

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  bool canIWin(int maxChoosableInteger, int desiredTotal) {
    int sum = (1 + maxChoosableInteger) * maxChoosableInteger / 2;
    if (sum < desiredTotal)  return false;
  	vector<bool> used(maxChoosableInteger + 1, false);
  	return helper(used, desiredTotal);
  }

  // whether the first player can win under such used conbination
  // return true when you have at least one choice to win the game
  // return false when under every choice you will fail the game
  bool helper(vector<bool> &used, int desiredTotal) {
  	// check if this combination tested before
  	int hash_int = hashInt(used);
  	if (map.find(hash_int) != map.end())  return map[hash_int];
  	// if not, check current combination
  	for (int i = used.size() - 1; i >= 1; --i) {
  		if (used[i])  continue;
  		// base case
  		if (i >= desiredTotal) {
  			map[hash_int] = true;  return true;
  		}
  		// choose this number & hash this combination to int
  		used[i] = true;
  		if (!helper(used, desiredTotal - i)) {
  			map[hash_int] = true;  used[i] = false;
        return true;
  		}
  		used[i] = false;
  	}
  	// no choice will make the first player win
  	map[hash_int] = false;  
    return false;
  }

  int hashInt(vector<bool> &used) {
  	int num = 0;
  	for (bool is_one : used) {
  		num <<= 1;
  		if (is_one)  num |= 1;
  	}
  	return num;
  }

 private:
 	unordered_map<int, bool> map;
};

int main() {
  Solution sol;
  cout << sol.canIWin(10, 11) << endl;
  return 0;
}