// Given two strings S and T, determine if they are both one edit distance apart.

// 长度相等，只允许一次replace
// 长度不等，只允许一次短的add / 长的delete
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int len1 = s.size(), len2 = t.size();
        if (abs(len1 - len2) > 1)  return false;
        int i = 0, j = 0;
        int distance = false;
        for (;i < len1 && j < len2; ++i, ++j) {
            if (s[i] == t[j])  continue;
            if (++distance > 1)  return false;
            if (len1 != len2) {
                (len1 < len2) ? --i : --j;
            }
        }
        if (i != len1 || j != len2)  ++distance;
        return (distance == 1) ? true : false;
    }
};

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int size1 = s.size(), size2 = t.size();
        if (abs(size1 - size2) > 1)  return false;
        int dp[size1 + 1][size2 + 1] = {};
        // base case
        for (int i = 0; i <= size1; ++i)  dp[i][0] = i;
        for (int j = 0; j <= size2; ++j)  dp[0][j] = j;
        // normal case
        for (int i = 1; i <= size1; ++i) {
            for (int j = 1; j <= size2; ++j) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j]));
                }
            }
        }
        // final result
        return dp[size1][size2] == 1;
    }
};