// In the computer world, use restricted resource you have to generate maximum benefit is 
// what we always want to pursue.

// For now, suppose you are a dominator of m 0s and n 1s respectively. On the other hand, 
// there is an array with strings consisting of only 0s and 1s.

// Now your task is to find the maximum number of strings that you can form with given 
// m 0s and n 1s. Each 0 and 1 can be used at most once.

// Note:
// The given numbers of 0s and 1s will both not exceed 100
// The size of given string array won't exceed 600.
// Example 1:
// Input: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
// Output: 4

// Explanation: This are totally 4 strings can be formed by the using of 5 0s and 3 1s, 
// which are “10,”0001”,”1”,”0”
// Example 2:
// Input: Array = {"10", "0", "1"}, m = 1, n = 1
// Output: 2

// Explanation: You could form "10", but then you'd have nothing left. Better form "0" and "1".

// 解法：opt[i][j][k]表示前i个string在j个0和k个1的限制下的最大个数，0-1背包变形
//      opt[i][j][k] = max{opt[i - 1][j - array[ix]_num0][k - array[ix]_num1] + 1, 
//                         opt[i - 1][j][k]}
// 感想：要根据递推表达式压缩空间，如果值更新的时候只参照前面的值，那么可以只用一维数组从尾开始往前面更新就不会影响

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
  int findMaxForm(vector<string>& strs, int m, int n) {
    vector<vector<int> > opt(m + 1, vector<int>(n + 1));
    int num0, num1;
    for (int i = 0; i < strs.size(); ++i) {
    	// count the number of zeros and ones of string
    	num0 = 0; 
    	for (char ch : strs[i]) {
    		if (ch == '0')  ++num0;
    	}
    	num1 = strs[i].size() - num0;
    	// fill the array
    	for (int j = m; j >= num0; --j) {
    		for (int k = n; k >= num1; --k) {
    			opt[j][k] = max(opt[j][k], 1 + opt[j - num0][k - num1]);
    		}
    	}
    }
    return opt[m][n];
  }
};

int main() {
	vector<string> strs = {"10", "0", "1"};
	Solution sol;
	cout << sol.findMaxForm(strs, 1, 1) << endl;

	return 0;
}