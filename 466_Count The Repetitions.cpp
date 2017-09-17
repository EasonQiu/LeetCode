// Define S = [s,n] as the string S which consists of n connected strings s. 
// For example, ["abc", 3] ="abcabcabc".

// On the other hand, we define that string s1 can be obtained from string s2 if we can 
// remove some characters from s2 such that it becomes s1. For example, “abc” can be obtained 
// from “abdbec” based on our definition, but it can not be obtained from “acbbe”.

// You are given two non-empty strings s1 and s2 (each at most 100 characters long) and two 
// integers 0 ≤ n1 ≤ 106 and 1 ≤ n2 ≤ 106. Now consider the strings S1 and S2, where S1=[s1,n1] 
// and S2=[s2,n2]. Find the maximum integer M such that [S2,M] can be obtained from S1.

// Example:
// Input:
// s1="acb", n1=4
// s2="ab", n2=2
// Return:
// 2

// opt[i] store a pair<count of s2(s), the index of the next letter to match>
// when opt[i] meet count = n2 && index == s2.size() - 1, ++ans
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  int getMaxRepetitions(string s1, int n1, string s2, int n2) {
  	if (s2.size() * n2 > s1.size() * n1)  return 0;
  	int curr_num = 0, curr_ix = 0;
  	int ans = 0;
  	for (int i = 0; i < n1; ++i) {
  		for (int j = 0; j < s1.size(); ++j) {
  			if (s2[curr_ix] != s1[j])  continue;
  			if (++curr_ix == s2.size()) {
  				curr_ix = 0;
  				if (++curr_num == n2) {
  					curr_num = 0;  ++ans;
  				}
  			}
  		}
  	}
  	return ans;
  }
};

int main() {
	Solution sol;
	cout << sol.getMaxRepetitions("acb", 4, "ab", 2) << endl;
	return 0;
}