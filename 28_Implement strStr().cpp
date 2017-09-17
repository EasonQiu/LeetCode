#include <iostream>
#include <string>

using namespace std;

class Solution { // KMP Substring Search, O(m + n)
public:
    int strStr(string haystack, string needle) {
        if (needle.empty())  return 0;
        if (haystack.empty() || haystack.size() < needle.size())  return -1;
        // init the kmp array
        vector<int> kmp(needle.size());
        int j = 0, i = 1;
        for (; i < needle.size(); ++i) {
            if (needle[i] == needle[j]) {
                kmp[i] = ++j;
            } else {
                while (j > 0 && needle[j] != needle[i])  j = kmp[j - 1];
                kmp[i] = (needle[j] == needle[i]) ? ++j : 0;
            }
        }
        // compare the str
        j = 0;  i = 0;
        while (j < haystack.size()) {
            if (haystack[j] == needle[i]) {
                ++j;  ++i;
                if (i == needle.size())  return j - i;
            } else {
                (i > 0) ? i = kmp[i - 1] : ++j;
            }
        }
        // final return
        return -1;
    }
};

class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle == "")  return 0;
		if (haystack.size() < needle.size())  return -1;
		for (unsigned int i = 0; i <= haystack.size() - needle.size(); ++i) {
			if (haystack[i] == needle[0]) {
				bool isFind = true;
				for (unsigned int j = 0; j < needle.size(); ++j) {
					if (haystack[i + j] != needle[j]) {
						isFind = false;  break;
					}
				}
				if (isFind)  return i;
			}
		}
		return -1;
	}
};

int main() {
	Solution sol;
	cout << sol.strStr("abcdefghi", "def") << endl;
	cout << sol.strStr("abcdefghi", "xyz") << endl;
	cout << sol.strStr("", "def") << endl;

	return 0;
}