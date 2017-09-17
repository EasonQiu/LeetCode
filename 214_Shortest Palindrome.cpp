// Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.

// For example:
// Given "aacecaaa", return "aaacecaaa".
// Given "abcd", return "dcbabcd".


class Solution {  // KMP, O(n)
public:
    string shortestPalindrome(string s) {
        string rev_s(s);
        reverse(rev_s.begin(), rev_s.end());
        string temp = s + '/' + rev_s;
        
        vector<int> kmp(temp.size());
        int j = 0; // index of prefix
        for (int i = 1; i < temp.size(); ++i) {
            if (temp[i] == temp[j]) {
                kmp[i] = ++j;
            } else {
                while (j > 0 && temp[i] != temp[j])  j = kmp[j - 1];
                kmp[i] = (temp[i] == temp[j]) ? ++j : 0;
            }
        }
        
        return rev_s.substr(0, rev_s.size() - kmp.back()) + s;
    }
};