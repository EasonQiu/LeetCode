// Given a string s and a list of strings dict, you need to add a closed pair of bold tag <b> and </b> to wrap the substrings in s that exist in dict. If two such substrings overlap, you need to wrap them together by only one pair of closed bold tag. Also, if two substrings wrapped by bold tags are consecutive, you need to combine them.

// Example 1:
// Input: 
// s = "abcxyz123"
// dict = ["abc","123"]
// Output:
// "<b>abc</b>xyz<b>123</b>"
// Example 2:
// Input: 
// s = "aaabbcc"
// dict = ["aaa","aab","bc"]
// Output:
// "<b>aaabbc</b>c"
// Note:
// The given dict won't contain duplicates, and its length won't exceed 100.
// All the strings in input have length in range [1, 1000].


class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        vector<bool> mark(s.size());
        for (string& word : dict) {
            int i = s.find(word, 0);
            while (i != s.npos) {
                for (int k = 0; k < word.size(); ++k)  mark[i + k] = true;
                i = s.find(word, i + 1);
            }
        }
        string ans = "";
        int i = 0;
        while (i < s.size()) {
            if (mark[i] == false) {
                ans += s[i++];
            } else {
                ans += "<b>";
                while (mark[i] == true)  ans += s[i++];
                ans += "</b>";
            }
        }
        return ans;
    }
};