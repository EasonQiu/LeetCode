#include <iostream>
#include <vector>

using namespace std;

// lindked list cycle II
class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		if (nums.size() <= 1)  return -1;
		int slow = 0;
		int fast = 0;
		do {
			fast = nums[nums[fast]];
			slow = nums[slow];
		} while (slow != fast);
		slow = 0;
		while (slow != fast) {
			slow = nums[slow];
			fast = nums[fast];
		}
		return slow;
	}
};


class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		if (nums.size() <= 1)  return -1;
		vector<int> counts(nums.size() + 1, 0);
		for (int n : nums) {
			if (++counts[n] > 1)  return n;
		}
		return -1;
	}
};

int main() {
	vector<int> nums = {0, 1, 2, 2};

	Solution sol;
	cout << sol.findDuplicate(nums) << endl;

	return 0;
}