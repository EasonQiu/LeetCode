// Given a string, determine if a permutation of the string could form a palindrome.

// For example,
// "code" -> False, "aab" -> True, "carerac" -> True.


class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> dict; // <char, count>
        for (char ch : s)  ++dict[ch];
        bool have_odd = false;
        for (auto &pair : dict) {
            if (pair.second % 2 == 1) {
                if (have_odd)  return false;
                have_odd = true;
            }
        }
        return true;
    }
};