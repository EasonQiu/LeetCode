// Given a string, find the length of the longest substring T that contains at most k distinct characters.

// For example, Given s = “eceba” and k = 2,

// T is "ece" which its length is 3.

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (s.empty() || k <= 0)  return 0;
        int dict[128] = {};  // <char, count>
        int max_len = 1;
        int count = 0;
        int left = 0;
        for (int right = 0; right < s.size(); ++right) {
            if (++dict[s[right]] == 1)  ++count;  // expand right
            while (count > k) {  // shrink left
                if (--dict[s[left++]] == 0)  --count;
            }
            max_len = max(max_len, right - left + 1);  // compare with max
        }
        return max_len;
    }
};