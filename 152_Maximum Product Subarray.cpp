// Find the contiguous subarray within an array (containing at least one number) which 
// has the largest product.

// For example, given the array [2,3,-2,4],
// the contiguous subarray [2,3] has the largest product = 6.

// 解法：max[i]表示以nums[i]为结尾的最大乘积。数字存在的时候要考虑为0的情况。
//      max[i] = max(nums[i], nums[i] * max[i - 1], nums[i] * min[i - 1])
//      min[i] = min(nums[i], nums[i] * max[i - 1], nums[i] * min[i - 1])

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
  int maxProduct(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    vector<int> max_pro(nums.size() + 1), min_pro(nums.size() + 1);
    int max_product = nums[0];
    // base case
    max_pro[0] = 1;  min_pro[0] = 1;
    // fill the array
    for (int i = 0; i < nums.size(); ++i) {
      max_pro[i + 1] = max(nums[i], max(nums[i] * max_pro[i], nums[i] * min_pro[i]));
      min_pro[i + 1] = max(nums[i], min(nums[i] * max_pro[i], nums[i] * min_pro[i]));
      max_product = max(max_product, max_pro[i + 1]);
    }
    // final result
    return max_product;
  }
};

int main() {
  vector<int> nums = {2, 0};

  Solution s;
  cout << s.maxProduct(nums) << endl;
  return 0;
}