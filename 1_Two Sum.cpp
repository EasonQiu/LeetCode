// Given an array of integers, return indices of the two numbers such that they add up to a specific target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// Example:
// Given nums = [2, 7, 11, 15], target = 9,

// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].


// 解法：检测是否hashmap中存在配对，如果没有则插入，如果有则return
// 感想：要注意返回的是value还是index!!!如果返回index不能简单sort

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// basic, O(n^2)
class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size() - 1; ++i) {
      for (int j = i + 1; j < nums.size(); ++j) {
        if (nums[i] + nums[j] == target) {
          return vector<int>{i, j};
        }
      }
    }
    return vector<int>{-1, -1};
  }
};

// sort + two pointers, O(nlogn)
// 如果只要求返回value，输出所有满足条件的解
class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int> > ans;
    int low = 0, high = nums.size() - 1;
    while (low < high) {
      if (nums[low] + nums[high] == target) {
        ans.push_back(vector<int>{nums[low], nums[high]});
        while (low < high && nums[low] == nums[low + 1])  ++low;
        while (low < high && nums[high] == nums[high - 1])  --high;
        ++low;  --high;
      } else if (nums[low] + nums[high] < target) {
        ++low;
      } else {
        --high;
      }
    }
    return ans;
  }
};

// hashmap, O(n)
class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); ++i) {
      if (map.find(target - nums[i]) != map.end()) {
        return vector<int>{map[target - nums[i]], i};
      }
      map[nums[i]] = i;
    }
    return vector<int>{-1, -1};
  }
};

int main() {
  vector<int> nums = {2, 7, 11, 2, 15};

  Solution s;
  vector<int> ans = s.twoSum(nums, 4);

  cout << ans[0] << " " << ans[1] << endl;

  return 0;
}