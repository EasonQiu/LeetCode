// Given a string S and a string T, find the minimum window in S which will 
// contain all the characters in T in complexity O(n).

// For example,
// S = "ADOBECODEBANC"
// T = "ABC"
// Minimum window is "BANC".

#include <iostream>
#include <string>

using namespace std;

// sliding window 可以解决的题目都是寻找一个最短或固定长度的substring，寻找最长的用不上
class Solution {
public:
    string minWindow(string s, string t) {
        int map[128] = {};
        for (int i = 0; i < t.size(); ++i)  ++map[t[i]];
        int min_start = -1, min_len = INT_MAX;
        int counter = t.size();
        int left = 0;
        for (int right = 0; right < s.size(); ++right) {
            // expand
            if (--map[s[right]] >= 0)  --counter;
            // shrink
            while (counter == 0) {
                if (right - left + 1 < min_len) {
                    min_len = right - left + 1;
                    min_start = left;
                }
                if (++map[s[left++]] > 0) ++counter;
            }
        }
        return min_len == INT_MAX ? "" : s.substr(min_start, min_len);
    }
};

int main() {
	Solution sol;
	cout << sol.minWindow("ADOBECODEBANC", "ABC") << endl;

	return 0;
}