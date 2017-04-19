#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pos = 0, posNew = 0;
        while (pos < (int)(nums.size() - 1)){
            while ((nums[pos + 1] == nums[pos]) && (pos <= (nums.size() -2) ))
                pos++;
            nums.erase(nums.begin() + posNew + 1, nums.begin() + pos + 1);
            pos = ++posNew;
        }
        return nums.size();
    }
};

int main() {
    int a[] = {};
    vector<int> nums(a,a+0);

    Solution s;
    s.removeDuplicates(nums);

    return 0;
}