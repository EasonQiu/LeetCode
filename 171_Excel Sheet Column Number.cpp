#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int answer = 0;
        for (int i = 0; i < s.size(); ++i) {
        	answer = answer * 26 + (s[i] - 64);
        }
        return answer;
    }
};

int main() {
	Solution s;
	cout << s.titleToNumber("AA") << endl;
	return 0;
}