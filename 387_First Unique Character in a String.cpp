// Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

// Examples:

// s = "leetcode"
// return 0.

// s = "loveleetcode",
// return 2.
// Note: You may assume the string contain only lowercase letters.


// int arr[26] = {-1}初始化无效
class Solution {
public:
    int firstUniqChar(string s) {
        int dict[26] = {};
        for (char ch : s)  ++dict[ch - 'a'];
        for (int i = 0; i < s.size(); ++i) {
            if (dict[s[i] - 'a'] == 1)  return i;
        }
        return -1;
    }
};