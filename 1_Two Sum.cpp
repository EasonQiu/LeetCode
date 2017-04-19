#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int, int> mapNums;
        map<int,int>::iterator pos;
        for (int i = 0; i < nums.size(); i++){
            pos = mapNums.find(target - nums[i]);
            if (pos == mapNums.end()){
                mapNums.insert(pair<int,int>(nums[i],i));
            }else {
                result.push_back(pos->second);
                result.push_back(i);
                break;
            }
        }
        return result;
    }
};

int main() {
    int a[] = {2,7,11,15};
    vector<int> nums(a, a+4);

    Solution s;
    s.twoSum(nums, 9);

    return 0;
}