// Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

// Examples: 
// [2,3,4] , the median is 3

// [2,3], the median is (2 + 3) / 2 = 2.5

// Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Your job is to output the median array for each window in the original array.

// For example,
// Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

// Window position                Median
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       1
//  1 [3  -1  -3] 5  3  6  7       -1
//  1  3 [-1  -3  5] 3  6  7       -1
//  1  3  -1 [-3  5  3] 6  7       3
//  1  3  -1  -3 [5  3  6] 7       5
//  1  3  -1  -3  5 [3  6  7]      6
// Therefore, return the median sliding window as [1,-1,-1,3,5,6].


class Solution { // multiset
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        if (k <= 1)  return vector<double>(nums.begin(), nums.end()); // corner case!
        multiset<int> window(nums.begin(), nums.begin() + k - 1);
        auto mid = next(window.begin(), (k - 1) / 2);
        vector<double> ans;
        for (int i = k - 1; i < nums.size(); ++i) {
            window.insert(nums[i]);
            int erase_num = nums[i - k + 1];
            auto erase_itr = window.lower_bound(erase_num);
            if (window.size() % 2 == 0) {
                if (nums[i] >= *mid)  ++mid;
                ans.push_back((double(*mid) + *prev(mid, 1)) / 2);
                if (erase_num > *mid || erase_itr == mid)  --mid;
            } else {
                if (nums[i] < *mid)  --mid;
                ans.push_back(double(*mid));
                if (erase_num <= *mid)  ++mid;
            }
            // erase in the end cuz mid may be erased!
            window.erase(erase_itr);
        }
        return ans;
    }
};


class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() < k)  return vector<double>();
        vector<double> ans(nums.size() - k + 1);
        int l = 0, r = 0;
        // init the map for first k - 1 numbers
        while (r < k - 1)  addNumber(nums[r++]);
        // calculate the medium
        for (;r < nums.size(); ++r) {
            addNumber(nums[r]);
            ans[l] = getMedium();
            popNumber(nums[l++]);
        }
        return ans;
    }
    
    void addNumber(int val) {
        if (size % 2 == 0) {
            ++small[val];
            auto small_max = --small.end();
            ++large[small_max->first];
            if (--small_max->second == 0)  small.erase(small_max);
        } else {
            ++large[val];
            auto large_min = large.begin();
            ++small[large_min->first];
            if (--large_min->second == 0)  large.erase(large_min);
        }
        ++size;
    }
    
    void popNumber(int val) {
        auto pos = small.find(val);
        if (pos != small.end()) { // val in the small set
            if (--pos->second == 0)  small.erase(pos);
            if (size % 2 == 1) {
                auto large_min = large.begin();
                ++small[large_min->first];
                if (--large_min->second == 0)  large.erase(large_min);
            }
        } else { // val in the large set
            pos = large.find(val);
            if (--pos->second == 0)  large.erase(pos);
            if (size % 2 == 0) {
                auto small_max = --small.end();
                ++large[small_max->first];
                if (--small_max->second == 0)  small.erase(small_max);
            }
        }
        --size;
    }
    
    double getMedium() {
        if (size % 2 == 1)  return double(large.begin()->first);
        else  return (double((--small.end())->first) + large.begin()->first) / 2;
    }
    
private:
    int size = 0;
    map<int, int> small, large; // number, count of number
};