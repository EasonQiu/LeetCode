// Given a string, find the length of the longest substring T that contains at most 2 distinct characters.

// For example, Given s = “eceba”,

// T is "ece" which its length is 3.

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if (s.size() <= 2)  return s.size();
        int max_len = 2;
        int dict[128] = {};
        int left = 0;
        int count = 0;
        for (int right = 0; right < s.size(); ++right) {
            if (++dict[s[right]] == 1)  ++count; // expand
            while (count > 2) { // shrink if necessary
                if (--dict[s[left++]] == 0)  --count;
            }
            max_len = max(max_len, right - left + 1); // update answer
        }
        return max_len;
    }
};