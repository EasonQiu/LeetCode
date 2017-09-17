// Given a word, you need to judge whether the usage of capitals in it is right or not.

// We define the usage of capitals in a word to be right when one of the following cases holds:

// All letters in this word are capitals, like "USA".
// All letters in this word are not capitals, like "leetcode".
// Only the first letter in this word is capital if it has more than one letter, like "Google".
// Otherwise, we define that this word doesn't use capitals in a right way.
// Example 1:
// Input: "USA"
// Output: True
// Example 2:
// Input: "FlaG"
// Output: False

class Solution {
public:
    bool detectCapitalUse(string word) {
        int upper_num = 0;
        for (char &ch : word) {
            if (isupper(ch))  ++upper_num;
        }
        if (upper_num == word.size() || upper_num == 0 || (upper_num == 1 && isupper(word[0]))) {
            return true;
        }
        return false;
    }
};

class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.size() <= 1)  return true;
        bool is_right = true;
        if (isupper(word[0])) {
            bool is_upper = (word[1] < 'a');
            for (int i = 2; i < word.size(); ++i) {
                if ((word[i] < 'a') != is_upper)  return false;
            }
        } else {
            for (int i = 1; i < word.size(); ++i) {
                if (word[i] < 'a')  return false;
            }
        }
        return true;
    }
};