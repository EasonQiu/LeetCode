#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
    	int n = s.size();
        vector<int> dp(n);
        // leftIx is the index of ( that hasn't found a pair
        int maxLen = 0, leftIx;
        for (int i = 1; i < n; ++i) {
        	if (s[i] == ')') {
        		leftIx = i - 1 - dp[i - 1];
        		if (leftIx >= 0 && s[leftIx] == '(')
        			dp[i] = dp[i - 1] + 2 + ((leftIx - 1 >= 0) ? dp[leftIx - 1] : 0);
        		maxLen = max(maxLen, dp[i]);
        	}
        }
        return maxLen;
    }
};

int main() {
	Solution s;
	cout << s.longestValidParentheses("()(()") << endl;
	return 0;
}