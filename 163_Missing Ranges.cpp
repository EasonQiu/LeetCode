// Given a sorted integer array where the range of elements are in the inclusive range [lower, upper], return its missing ranges.

// For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, return ["2", "4->49", "51->74", "76->99"].

// corner cases: [],1,1   [1,1,1],1,1   [-2147483648,2147483647],-2147483648,2147483647
class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        if (lower > upper)  return vector<string>();
        vector<string> ans;
        int left = 0, right = int(nums.size()) - 1;
        while (left <= right && nums[left] < lower)  ++left;
        while (left <= right && nums[right] > upper)  --right;
        if (left > right) { // corner case
            if (lower == upper) {
                return vector<string>{to_string(lower)};
            } else {
                return vector<string>{to_string(lower) + "->" + to_string(upper)};
            }
        }
        if (lower < nums[left]) { // left part
            if (lower + 1 == nums[left]) {
                ans.push_back(to_string(lower));
            } else {
                ans.push_back(to_string(lower) + "->" + to_string(nums[left] - 1));
            }
        }
        for (left = left + 1; left <= right; ++left) { // mid part
            if (nums[left - 1] == nums[left] || nums[left - 1] + 1 == nums[left])  continue;
            if (nums[left - 1] + 2 == nums[left]) {
                ans.push_back(to_string(nums[left - 1] + 1));
            } else {
                ans.push_back(to_string(nums[left - 1] + 1) + "->" + to_string(nums[left] - 1));
            }
        }
        if (nums[right] < upper) { // right part
            if (nums[right] + 1 == upper) {
                ans.push_back(to_string(upper));
            } else {
                ans.push_back(to_string(nums[right] + 1) + "->" + to_string(upper));
            }
        }
        return ans;
    }
};