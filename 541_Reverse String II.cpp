// Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.
// Example:
// Input: s = "abcdefg", k = 2
// Output: "bacdfeg"
// Restrictions:
// The string consists of lower English letters only.
// Length of the given string and k will in the range [1, 10000]


class Solution {
public:
    string reverseStr(string s, int k) {
        int left = 0, size = s.size();
        while (left < s.size()) {
            int right = min(left + k, size);
            reverse(s.begin() + left, s.begin() + right);
            left += 2 * k;
        }
        return s;
    }
};