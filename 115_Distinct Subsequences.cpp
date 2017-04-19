#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = t.size(), m = s.size();
        vector<vector<int> > dp(n + 1, vector<int>(m + 1));
        // init the base case
        for (int i = 0; i < m + 1; ++i) {
        	dp[0][i] = 1;
        }
        // recursion
        for (int i = 1; i < n + 1; ++i) {
        	for (int j = 1; j < m + 1; ++j) {
        		if (s[j - 1] == t[i - 1]) {
        			dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
        		} else {
        			dp[i][j] = dp[i][j - 1];
        		}
        	}
        }
        return dp[n][m];
    }
};

int main() {

}