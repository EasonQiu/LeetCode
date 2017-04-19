#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	// O(n^2) version
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<int> f(n, 1);
        for (int j = 0; j < n; ++j) {
        	for (int i = 0; i < j; ++i) {
        		if (nums[i] < nums[j] && f[j] < f[i] + 1)  
        			f[j] = f[i] + 1;
        	}
        	ans = max(ans, f[j]);
        }
        return ans;
    }
};

int main() {
	int arr[8] = {10, 9, 2, 5, 3, 7, 101, 18};
	vector<int> nums(arr, arr+8);
	Solution s;
	cout << s.lengthOfLIS(nums) << endl;
	return 0;
}