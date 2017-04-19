#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i) {
        	if (++map[nums[i]] == 2)  map.erase(nums[i]);
        }
        return map.begin()->first;
    }
};

int main() {
	int arr[] = {1,3,4,4,1};
	vector<int> nums(arr, arr+5);

	Solution s;
	cout << s.singleNumber(nums);

	return 0;
}