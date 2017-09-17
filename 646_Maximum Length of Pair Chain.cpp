// You are given n pairs of numbers. In every pair, the first number is always smaller than the second number.

// Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c. Chain of pairs can be formed in this fashion.

// Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the given pairs. You can select pairs in any order.

// Example 1:
// Input: [[1,2], [2,3], [3,4]]
// Output: 2
// Explanation: The longest chain is [1,2] -> [3,4]
// Note:
// The number of given pairs will be in the range [1, 1000].



class Compare {
public:
    bool operator() (vector<int> &lhs, vector<int> &rhs) {
        return lhs[1] < rhs[1];
    }
};

class Solution {  // Greedy
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if (pairs.empty())  return 0;
        sort(pairs.begin(), pairs.end(), Compare());
        int max_len = 1;
        int prev_end = pairs[0][1];
        for (int i = 1; i < pairs.size(); ++i) {
            if (pairs[i][0] <= prev_end)  continue;
            ++max_len;
            prev_end = pairs[i][1];
        }
        return max_len;
    }
};

class Solution {  // DP
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if (pairs.empty())  return 0;
        sort(pairs.begin(), pairs.end(), Compare());
        vector<int> dp(pairs.size(), 1);
        int max_len = 1;
        for (int i = 1; i < pairs.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (pairs[j][1] >= pairs[i][0])  break;
                dp[i] = max(dp[i], dp[j] + 1);
            }
            max_len = max(max_len, dp[i]);
        }
        return max_len;
    }
};