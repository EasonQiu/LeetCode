#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int index;
        map<int, int> numsMap;
        map<int, int>::iterator iter;

        for (int i = 0; i < nums.size(); i++){
            if (nums.size() == 1){
                index = nums[i]; break;
            }
            iter  = numsMap.find(nums[i]);
            if (iter == numsMap.end()){
                numsMap.insert(pair<int,int>(nums[i], 1));
            }else {
                if ((++iter->second) > (nums.size() / 2) ) {
                    index = iter->first;  break;
                }
            }
        }

        return index;
    }
};

int main() {
    int a[] = {1};
    vector<int> nums(a, a+1);
    Solution s;

    cout << s.majorityElement(nums);

    return 0;
}