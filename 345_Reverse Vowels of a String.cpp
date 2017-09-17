// Write a function that takes a string as input and reverse only the vowels of a string.

// Example 1:
// Given s = "hello", return "holle".

// Example 2:
// Given s = "leetcode", return "leotcede".

// 解法：两相对指针同时向中间扫描，直到碰到为止
// 感想：对撞型指针的写法要记住，swap在algorithm这个库下面

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

class Solution {
public:
  string reverseVowels(string s) {
  	if (s.size() <= 1)  return s;
  	int left = 0, right = s.size() - 1;
  	while (left < right) {
  		// find the next vowels on two sides
  		while (left < right && !isVowels(s[left]))  ++left;
  		while (left < right && !isVowels(s[right]))  --right;
  		// swap two vowels
  		if (left < right)  swap(s[left++], s[right--]);
  	}
  	// final result
  	return s;
  }

  bool isVowels(char ch) {
  	ch = tolower(ch);
  	if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')  
  		return true;
  	return false;
  }
};

int main() {
	Solution sol;
	cout << sol.reverseVowels("leetcode") << endl;
	cout << sol.reverseVowels("ddd") << endl;
	cout << sol.reverseVowels("OE") << endl;

	return 0;
}


