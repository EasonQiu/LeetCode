// Given an array of strings, group anagrams together.

// For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
// Return:

// [
//   ["ate", "eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]
// Note: All inputs will be in lower-case.

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > ans;
        unordered_map<string, vector<string> > map;
        for (string &str : strs) {
            string copy = str;
            sort(copy.begin(), copy.end());
            map[copy].push_back(str);
        }
        for (auto &pair : map) {
            ans.push_back(pair.second);
        }
        return ans;
    }
};