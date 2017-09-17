#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  string reverseString(string s) {
  	if (s.size() <= 1)  return s;
  	unsigned int left = 0, right = s.size() - 1;
  	while (left < right) {
  		swap(s[left++], s[right--]);
  	}
  	return s;
  }
};

int main() {
	Solution sol;
	cout << sol.reverseString("hello") << endl;

	return 0;
}