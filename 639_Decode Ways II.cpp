// A message containing letters from A-Z is being encoded to numbers using the following mapping way:

// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
// Beyond that, now the encoded string can also contain the character '*', which can be treated as one of the numbers from 1 to 9.

// Given the encoded message containing digits and the character '*', return the total number of ways to decode it.

// Also, since the answer may be very large, you should return the output mod 109 + 7.

// Example 1:
// Input: "*"
// Output: 9
// Explanation: The encoded message can be decoded to the string: "A", "B", "C", "D", "E", "F", "G", "H", "I".
// Example 2:
// Input: "1*"
// Output: 9 + 9 = 18
// Note:
// The length of the input string will fit in range [1, 105].
// The input string will only contain the character '*' and digits '0' - '9'.


// 两位的02*各种排列组合
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0')  return 0;
        int size = s.size();
        long dp[size + 1] = {};
        dp[0] = 1; // for '2*...' or '19...' 
        dp[1] = (s[0] == '*') ? 9 : 1;  // base case
        for (int i = 1; i < size; ++i) {
            if (s[i] == '*') {
                dp[i + 1] = dp[i] * 9;
                if (s[i - 1] == '1' || s[i - 1] == '*')  dp[i + 1] += dp[i - 1] * 9; // 11~19
                if (s[i - 1] == '2' || s[i - 1] == '*')  dp[i + 1] += dp[i - 1] * 6; // 21~26
            } else if (s[i] != '0') {
                dp[i + 1] = dp[i];
                if (s[i - 1] == '1')  dp[i + 1] += dp[i - 1];
                if (s[i - 1] == '2' && s[i] <= '6')  dp[i + 1] += dp[i - 1];
                if (s[i - 1] == '*')  dp[i + 1] += (s[i] <= '6') ? 2 * dp[i - 1] : dp[i - 1];
            } else {
                if (s[i - 1] != '1' && s[i - 1] != '2' && s[i - 1] != '*')  return 0;
                dp[i + 1] = (s[i - 1] == '*') ? 2 * dp[i - 1] : dp[i - 1];
            }
            dp[i + 1] %= 1000000007;
        }
        return dp[size];
    }
};