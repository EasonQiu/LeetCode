// Given an encoded string, return it's decoded string.

// The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

// You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

// Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

// Examples:

// s = "3[a]2[bc]", return "aaabcbc".
// s = "3[a2[c]]", return "accaccacc".
// s = "2[abc]3[cd]ef", return "abcabccdcdcdef".

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        if (s.empty())  return s;
        string ans = "";
        int i = 0;
        while (i < s.size()) {
            if (isalpha(s[i])) {
                ans += s[i++];  continue;
            }
            // find the left of '['
            int left = i;
            while (left < s.size() && s[left] != '[')  ++left;
            // find the pos of ']'
            int stack = 1;
            int right = left + 1;
            while (stack != 0) {
                (s[right] == '[') ? ++stack : (s[right] == ']') ? --stack : stack;
                ++right;
            }
            // decode the substring found
            string decoded = decodeString(s.substr(left + 1, right - left - 2));
            for (int k = 0; k < stoi(s.substr(i, left - i)); ++k) {
                ans += decoded;
            }
            i = right;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    cout << sol.decodeString("2[abc]3[cd]ef") << endl;
}