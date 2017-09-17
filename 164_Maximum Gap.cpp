// Given an unsorted array, find the maximum difference between the successive elements 
// in its sorted form.
// Try to solve it in linear time/space.
// Return 0 if the array contains less than 2 elements.

// You may assume all elements in the array are non-negative integers and fit in the 32-bit 
// signed integer range.

// 需要用到sort且要求时间复杂度为O(n)时，要考虑到用bucket sort
// 这道题有一个关键点是，max_gap有个最低界限是 (maxV - minV) / (size - 1)
// 然后利用bucket的一个特点，就是同一个桶内数据之间的最大差值不会超过这个bucket的范围
// 如果把上面的最低界限作为bucket的范围，可以只考虑这个桶的最大最小值
class Solution {
public:
  int maximumGap(vector<int>& nums) {
  	if (nums.size() <= 1)  return 0;
  	int size = nums.size();
  	// calculate the max and min value in nums array
  	int max_num = INT_MIN, min_num = INT_MAX;
  	for (int num : nums) {
  		max_num = max(max_num, num);
  		min_num = min(min_num, num);
  	}
  	// calculate the lower bound of maximum gap, and init the bucket array
  	int bucket_gap  = max(1, (max_num - min_num) / (size -  1));
  	int bucket_size = (max_num - min_num) / bucket_gap + 1;
  	vector<int> maxs(bucket_size, INT_MIN);
  	vector<int> mins(bucket_size, INT_MAX);
  	// insert nums into bucket array
  	int index;
  	for (int num : nums) {
  		index = (num - min_num) / bucket_gap;
  		maxs[index] = max(maxs[index], num);
  		mins[index] = min(mins[index], num);
  	}
  	// calculate the max gap
  	int max_gap = 0, last_max = INT_MIN;
  	for (int i = 0; i < bucket_size; ++i) {
  		if (maxs[i] == INT_MIN)  continue;
  		if (last_max != INT_MIN) {
  			max_gap = max(max_gap, mins[i] - last_max);
  		}
  		last_max = maxs[i];
  	}
  	// return value
  	return max_gap;
  }
};