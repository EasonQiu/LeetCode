class NumArray {
public:
    NumArray(vector<int> nums) {
        if (nums.size() == 0)  return;
        int size = nums.size();
        dp.resize(size + 1);
        for (int i = 1; i <= size; ++i) {
            dp[i] = dp[i - 1] + nums[i - 1];
        }
    }
    
    int sumRange(int i, int j) {
        return dp[j + 1] - dp[i];
    }
    
private:
    vector<int> dp; // sum of index[begin, end)
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */