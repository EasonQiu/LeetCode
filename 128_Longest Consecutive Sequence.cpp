// Given an unsorted array of integers, find the length of the longest consecutive 
// elements sequence.

// For example,
// Given [100, 4, 200, 1, 3, 2],
// The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
// Your algorithm should run in O(n) complexity.

// 解法：hashmap保存每个number对应的连续数组的长度，每次查找num-1和num+1是否存在。将数组长度保存在首尾节点中。

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    if (nums.size() == 0)  return 0;
    unordered_map<int, int> map; // <number, length>
    int max_len = 1, left_len, right_len, len;
    for (int num : nums) {
      if (map.find(num) != map.end())  continue;
      left_len  = (map.find(num - 1) != map.end()) ? map[num - 1] : 0;
      right_len = (map.find(num + 1) != map.end()) ? map[num + 1] : 0;
      len = left_len + right_len + 1;
      map[num] = len;  map[num - left_len]  = len;  map[num + right_len] = len;
      max_len = max(max_len, len);
    }
    return max_len;
  }
};

int main() {
	int arr[] = {100, 4, 200, 1, 3, 2};
	vector<int> nums(arr, arr + 6);

	Solution s;
	cout << s.longestConsecutive(nums) << endl;
	return 0;
}