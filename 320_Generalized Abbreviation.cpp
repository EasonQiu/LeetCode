// Write a function to generate the generalized abbreviations of a word.

// Example:
// Given word = "word", return the following list (order does not matter):
// ["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]


class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        if (word == "")  return vector<string>{""};
        vector<string> startChar = getAbbr(word, 0, true);
        vector<string> startNum = getAbbr(word, 0, false);
        for (string &abbr : startNum)  startChar.push_back(abbr);
        return startChar;
    }
    
    vector<string> getAbbr(string word, int j, bool is_char_start) {
        if (j == word.size())  return vector<string>{""};
        vector<string> ans;
        for (int i = j; i < word.size(); ++i) {
            string prefix = (is_char_start) ? word.substr(j, i - j + 1) : to_string(i - j + 1);
            vector<string> suffix = getAbbr(word, i + 1, !is_char_start);
            for (string &str : suffix)  ans.push_back(prefix + str);
        }
        return ans;
    }
};