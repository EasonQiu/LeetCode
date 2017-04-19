#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
//        return max_element(nums.begin(), nums.end()) - nums.begin();
        int left = 0, right = nums.size() - 1, mid;
        while (left <= right){
            mid = (left + right) / 2;
            if (left == right){
                break;
            }else {
                if (nums[mid] > nums[mid+1]) {
                    right = mid;
                }else {
                    left = mid + 1;
                }
            }
        }
        return left;
    }
};

int main() {
    int a[] = {1,2,3,4};
    vector<int> nums(a,a+4);

    Solution s;
    cout << s.findPeakElement(nums);

    return 0;
}