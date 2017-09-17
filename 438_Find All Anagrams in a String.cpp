// Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

// Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

// The order of output does not matter.

// Example 1:

// Input:
// s: "cbaebabacd" p: "abc"

// Output:
// [0, 6]

// Explanation:
// The substring with start index = 0 is "cba", which is an anagram of "abc".
// The substring with start index = 6 is "bac", which is an anagram of "abc".


// sliding window
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if (s == "" || p == "" || s.size() < p.size())  return ans;
        int dict[128] = {};
        for (char ch : p)  ++dict[ch];
        int count = p.size();
        int left = 0;
        for (int right = 0; right < s.size(); ++right) {
            if (--dict[s[right]] >= 0)  --count;
            if (count == 0)  ans.push_back(left);
            if (right + 1 >= p.size() && ++dict[s[left++]] > 0)  ++count;
        }
        return ans;
    }
};