// Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:

// "abc" -> "bcd" -> ... -> "xyz"
// Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.

// For example, given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"], 
// A solution is:

// [
//   ["abc","bcd","xyz"],
//   ["az","ba"],
//   ["acef"],
//   ["a","z"]
// ]


class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string> > pattern; // <diff, words>
        for (string& word : strings) {
            string diff = "";
            for (int i = 1; i < word.size(); ++i) {
                int d = word[i] - word[0];
                if (d < 0) d += 26;
                diff += char('A' + d) + ' ';
            }
            pattern[diff].push_back(word);
        }
        vector<vector<string> > ans;
        for (auto& pair : pattern)  ans.push_back(pair.second);
        return ans;
    }
};