#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output(nums.size());
        vector<int> factor1(nums.size(),1), factor2(nums.size(),1);
        for (int i = 1; i < nums.size(); i++){
            factor1[i] = factor1[i-1] * nums[i-1];
            factor2[nums.size()-1-i] = factor2[nums.size()-i] * nums[nums.size()-i];
        }
        for (int i = 0; i < nums.size(); i++){
            output[i] = factor1[i] * factor2[i];
        }
        return output;
    }
};

int main() {
    int a[] = {0,0};
    vector<int> nums(a,a+2);

    Solution s;
    s.productExceptSelf(nums);

    return 0;
}