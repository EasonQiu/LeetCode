// Now you are given a string S, which represents a software license key which we would like to format. The string S is composed of alphanumerical characters and dashes. The dashes split the alphanumerical characters within the string into groups. (i.e. if there are M dashes, the string is split into M+1 groups). The dashes in the given string are possibly misplaced.

// We want each group of characters to be of length K (except for possibly the first group, which could be shorter, but still must contain at least one character). To satisfy this requirement, we will reinsert dashes. Additionally, all the lower case letters in the string must be converted to upper case.

// So, you are given a non-empty string S, representing a license key to format, and an integer K. And you need to return the license key formatted according to the description above.

// Example 1:
// Input: S = "2-4A0r7-4k", K = 4

// Output: "24A0-R74K"

// Explanation: The string S has been split into two parts, each part has 4 characters.

// corner case是头里面有无'-'要检测
// string的前插比后插要慢好多！估计string是一个vector<char>, insert要O(n)
class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        if (S.empty())  return S;
        string ans = "";
        int count = 0;
        for (int i = S.size() - 1; i >= 0; --i) {
            if (S[i] == '-')  continue;
            ans += toupper(S[i]);
            if (++count == K) {
                ans += '-';
                count = 0;
            }
        }
        reverse(ans.begin(), ans.end());
        if (ans[0] == '-')  ans.erase(0, 1);
        return ans;
    }
};