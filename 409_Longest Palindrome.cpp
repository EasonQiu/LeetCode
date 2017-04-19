#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
	int longestPalindrome(string s) { // beats 66.44%
        vector<int> dict(256, 0);
        int maxLen = 0;
        for (int i = 0; i < s.size(); ++i) {
        	if (++dict[s[i] - '\0'] == 2) {
        		dict[s[i] - '\0'] = 0;  maxLen += 2;
        	}
        }
        for (int val : dict) {
			if (val == 1)  return maxLen + 1;
		}
        return maxLen;
    }

    int longestPalindrome2(string s) {
        unordered_map<char, int> dict(s.size());
        int maxLen = 0;
        for (int i = 0; i < s.size(); ++i) {
        	if (++dict[s[i]] == 2) {
        		dict.erase(s[i]);  maxLen += 2;
        	}
        }
        if (!dict.empty())  return maxLen + 1;
        return maxLen;
    }
};

int main() {
	Solution s;
	cout << s.longestPalindrome("cc") << endl;

	return 0;
}