// Given a string, determine if it is a palindrome, considering only alphanumeric characters 
// and ignoring cases.

// For example,
// "A man, a plan, a canal: Panama" is a palindrome.
// "race a car" is not a palindrome.

// 解法：首尾两指针向中间扫描，用isalnum判断是否需跳过当前字符
// 感想：记住一些常用函数所在的库名，tolower函数如果不是字符就会返回原字符

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		if (s.size() == 0)  return true;
		unsigned int forward_itr = 0, backward_itr = s.size() - 1;
		bool is_palindrome = true;
		// two pointers
		while (forward_itr < backward_itr) {
			// the cases when they are not alphanumeric chars
			if (!isalnum(s[forward_itr])) {
				++forward_itr;  continue;
			} else if (!isalnum(s[backward_itr])) {
				--backward_itr; continue;
			}
			// the cases when they are both alphanumeric chars
			if (tolower(s[forward_itr]) == tolower(s[backward_itr])) {
				++forward_itr;  --backward_itr;
			} else {
				is_palindrome = false;  break;
			}
		}
		// final result
		return is_palindrome;
  }
};

int main() {
	Solution sol;
	cout << sol.isPalindrome("A man, a plan, a canal: Panama") << endl;
	cout << sol.isPalindrome(" :,") << endl;
	cout << sol.isPalindrome(" ad gd  ") << endl;

	return 0;
}