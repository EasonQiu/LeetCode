#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string ans = "";
        for (string word : d) {
        	int pos = 0;
        	for (char ch : s) {
        		if (ch == word[pos])  ++pos;
        	}
        	if (pos == word.size()) {
        		if (word.size() > ans.size() || (word.size() == ans.size() && word < ans))
        			ans = word;
        	}
        }
        return ans;
    }
};

int main() {
	string s = "abpcplea";
	vector<string> d = {"ale", "apple", "monkey", "plea"};

	Solution solution;
	cout << solution.findLongestWord(s, d) << endl;

	return 0;
}