#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> maxPro(nums.size(),0), minPro(nums.size(),0);
        maxPro[0] = minPro[0] = nums[0];
        int maxResult = nums[0];
        for (int i=1; i<nums.size(); i++){
            maxPro[i] = max(nums[i], max(maxPro[i-1]*nums[i],maxPro[i-1]*nums[i]));
            minPro[i] = min(nums[i], min(minPro[i-1]*nums[i],minPro[i-1]*nums[i]));

            maxResult = max(maxPro[i],maxResult);
        }
        return maxResult;
    }
};

int main() {
    int a[] = {-2,0,-1};
    vector<int> nums(a,a+3);

    Solution s;
    cout << s.maxProduct(nums);
    return 0;
}