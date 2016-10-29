#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        set<int> setNum;
        for (int i = 0; i <= nums.size(); i++)
            setNum.insert(i);
        for (int i = 0; i < nums.size(); i++)
            setNum.erase(nums[i]);
        return *setNum.begin();
    }
};

int main() {
    int a[] = {0};
    vector<int> nums(a,a+1);

    Solution s;
    cout << s.missingNumber(nums);

    return 0;
}