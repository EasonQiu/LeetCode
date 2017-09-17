// Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.

// Example 1:
// Input: "abab"

// Output: True

// Explanation: It's the substring "ab" twice.
// Example 2:
// Input: "aba"

// Output: False


class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if (s.size() <= 1)  return false;
        int size = s.size();
        for (int i = 1; i <= size / 2; ++i) {
            if (s[i] != s.front() || s[i - 1] != s.back())  continue;
            if (size % i != 0)  continue;
            string base = s.substr(0, i);
            int j;
            for (j = i; j < size; j += i) {
                if (s.substr(j, i) != base)  break;
            }
            if (j == size)  return true;
        }
        return false;
    }
};