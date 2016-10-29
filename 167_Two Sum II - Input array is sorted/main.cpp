#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Using Binary Search
class Solution {
public:
    int biSearch(const vector<int>& nums, int target, int left, int right){
        int index = -1;
        int middle = (left + right) / 2;
        if (left == right) {
            if (nums[left] == target) index = left;
        }else {
            if (nums[middle] == target) {
                index = middle;
            }else if (nums[middle] > target){
                index = biSearch(nums, target, left, middle);
            }else if (nums[middle] < target){
                index = biSearch(nums, target, middle + 1, right);
            }
        }
        return index;
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        int pos2;
        for (int pos1 = 0; pos1 + 1< nums.size(); pos1++){
            pos2 = biSearch(nums, target - nums[pos1], pos1 + 1, (int)(nums.size()) - 1);
            if (pos2 != -1) {
                result.push_back(pos1 + 1); result.push_back(pos2 + 1);
                break;
            }
        }
        return result;
    }
};

int main() {
    int a[] = {2,7,11,15};
    vector<int> nums(a, a+4);

    Solution s;
    s.twoSum(nums, 13);

    return 0;
}