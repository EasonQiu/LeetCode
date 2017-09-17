// There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of non-empty words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.

// Example 1:
// Given the following words in dictionary,
// [
//   "wrt",
//   "wrf",
//   "er",
//   "ett",
//   "rftt"
// ]
// The correct order is: "wertf".

// Example 3:
// Given the following words in dictionary,
// [
//   "z",
//   "x",
//   "z"
// ]
// The order is invalid, so return "".

// Note:
// You may assume all letters are in lowercase.
// You may assume that if a is a prefix of b, then a must appear before b in the given dictionary.
// If the order is invalid, return an empty string.
// There may be multiple valid order of letters, return any one of them is fine.

class Solution {
public:
    string alienOrder(vector<string>& words) {
        if (words.empty())  return "";
        // init the out_degree and in_degree
        vector<vector<char> > out_degree(128);
        vector<int> in_degree(128);
        unordered_set<char> chars;
        for (int i = 0; i < words.size(); ++i) {
            for (char ch : words[i])  chars.insert(ch);
            for (int j = i + 1; j < words.size(); ++j) {
                int k;
                for (k = 0; k < words[i].size() && k < words[j].size(); ++k) {
                    if (words[i][k] != words[j][k])  break;
                }
                if (k != words[i].size() && k != words[j].size()) {
                    out_degree[words[i][k]].push_back(words[j][k]);
                    in_degree[words[j][k]]++;
                }
            }
        }
        // init the zero_in_degree
        queue<char> zero_in_degree;
        for (char ch : chars) {
            if (in_degree[ch] == 0)  zero_in_degree.push(ch);
        }
        // topological sort
        string ans = "";
        while (!zero_in_degree.empty()) {
            char ch = zero_in_degree.front();
            zero_in_degree.pop();
            ans += ch;
            for (char next : out_degree[ch]) {
                if (--in_degree[next] == 0)  zero_in_degree.push(next);
            }
        }
        // final result
        return (ans.size() == chars.size()) ? ans : "";
    }
};