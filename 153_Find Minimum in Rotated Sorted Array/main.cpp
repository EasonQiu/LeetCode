#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, middle;
        while (left <= right){
            middle = (left + right) / 2;
            if (left == right){
                break;
            }else if (nums[middle] > nums[middle + 1]){
                left = middle + 1; break;
            }else if (nums[middle] > nums[right]){
                left = middle + 1;
            }else {
                right = middle;
            }
        }
        return nums[left];
    }
};

int main() {
    int a[] = {1,2,3,0};
    vector<int> nums(a,a+4);

    Solution s;
    cout << s.findMin(nums);

    return 0;
}