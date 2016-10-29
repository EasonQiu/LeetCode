#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int left = 0, right = 0;
        string str;
        while (left < nums.size()){
            while (right + 1 < nums.size()){
                if (nums[right + 1] - nums[right] == 1) right++;
                else break;
            }
            if (left == right){
                str = to_string(nums[left]);
                result.push_back(str);
            }else {
                str = to_string(nums[left]) + "->" + to_string(nums[right]);
                result.push_back(str);
            }
            left  = right + 1;  right = left;
        }
        return result;
    }
};

int main() {
    int a[] = {0,1,2,4,5,7};
    vector<int> nums(a,a+6);

    Solution s;
    s.summaryRanges(nums);

    return 0;
}