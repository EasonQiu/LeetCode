// Given an input string, reverse the string word by word. A word is defined as a sequence of non-space characters.

// The input string does not contain leading or trailing spaces and the words are always separated by a single space.

// For example,
// Given s = "the sky is blue",
// return "blue is sky the".

// Could you do it in-place without allocating extra space?


class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        int left = 0;
        int right = 0;
        while (left < s.size()) {
            while (right < s.size() && s[right] != ' ')  ++right;
            reverse(s.begin() + left, s.begin() + right);
            left = right + 1;
            right = left;
        }
    }
};