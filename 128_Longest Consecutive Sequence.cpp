#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() <= 1)  return nums.size();
        unordered_map<int, int> map();
        int maxLen = 1, left, right, length;
        for (int num : nums) {
        	// find the length of the number next to num
        	if (map.find(num) != map.end())  continue;
        	left  = map.find(num - 1) == map.end() ? 0 : map[num - 1];
        	right = map.find(num + 1) == map.end() ? 0 : map[num + 1];
        	// union the length of on two sides
        	length = left + right + 1;
        	map[num] = length;  map[num - left] = length;  map[num + right] = length;
        	// compare with the current max length
        	maxLen = max(maxLen, length);
        }
        return maxLen;
    }
};

int main() {
	int arr[] = {100, 4, 200, 1, 3, 2};
	vector<int> nums(arr, arr + 6);

	Solution s;
	cout << s.longestConsecutive(nums) << endl;
	return 0;
}