#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <numeric>
#include <map>

using namespace std;

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
        else  return double((--small.end())->first + large.begin()->first) / 2;
    }
    
private:
    int size = 0;
    map<int, int> small, large; // number, count of number
};

int main() {
    Solution solu;
    vector<int> nums = {1,4,2,3};
    vector<double> ans = solu.medianSlidingWindow(nums, 4);
    for (double val : ans) cout << val << " ";
    
    return 0;
}