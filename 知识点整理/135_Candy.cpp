// There are N children standing in a line. Each child is assigned a rating value.

// You are giving candies to these children subjected to the following requirements:

// Each child must have at least one candy.
// Children with a higher rating get more candies than their neighbors.
// What is the minimum candies you must give?


class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.size() <= 1)  return ratings.size();
        int size = ratings.size();
        vector<int> nums(size, 1);
        for (int i = 1; i < size; ++i) { // ascending
            if (ratings[i] <= ratings[i - 1])  continue;
            nums[i] = nums[i - 1] + 1;
        }
        for (int i = size - 2; i >= 0; --i) { // descending
            if (ratings[i] <= ratings[i + 1])  continue;
            nums[i] = max(nums[i], nums[i + 1] + 1);
        }
        return accumulate(nums.begin(), nums.end(), 0);
    }
};