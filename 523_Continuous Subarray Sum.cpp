// Given a list of non-negative numbers and a target integer k, write a function to 
// check if the array has a continuous subarray of size at least 2 that sums up to 
// the multiple of k, that is, sums up to n*k where n is also an integer.

// Example 1:
// Input: [23, 2, 4, 6, 7],  k=6
// Output: True
// Explanation: Because [2, 4] is a continuous subarray of size 2 and sums up to 6.
// Example 2:
// Input: [23, 2, 6, 4, 7],  k=6
// Output: True
// Explanation: Because [23, 2, 6, 4, 7] is an continuous subarray of size 5 and sums up to 42.

// 解法：计算所有0到i的sum，如果当前的余数之前出现过且两者index差大于1，则返回true
// 感想：碰到/或者%要考虑除数是否为0, 6 % -3 = 0。数的倍数包括正负。
//      hashmap的insert如果有key存在则不会插入

class Solution { // O(n)
public:
  bool checkSubarraySum(vector<int>& nums, int k) {
  	if (nums.size() <= 1)  return false;
    if (nums.size() >= 2 * abs(k) && abs(k) > 0)  return true;
    unordered_map<int, int> map; // <remainder, index>
    map.emplace(0, -1);  // for case: [0, 0] 0
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
    	sum = (k == 0) ? sum + nums[i] : (sum + nums[i]) % k;
    	if (map.find(sum) != map.end() && i - map[sum] > 1)  return true;
    	map.insert(make_pair(sum, i));
    }
    return false;
  }
};

class Solution { // dp, memory limit exceed
public:
  bool checkSubarraySum(vector<int>& nums, int k) {
  	vector<unordered_set<int> > opt(nums.size(), unordered_set<int>());
  	int val;
    for (int i = 1; i < nums.size(); ++i) {
        val = k == 0 ? nums[i - 1] + nums[i] : (nums[i - 1] + nums[i]) % k;
    	if (val == 0)  return true;
    	opt[i].insert(val);
    	for (int remainder : opt[i - 1]) {
    	    val = k == 0 ? nums[i - 1] + nums[i] : (remainder + nums[i]) % k;
    		if (val == 0)  return true;
    		opt[i].insert(val);
    	}
    }
    return false;
  }
};
