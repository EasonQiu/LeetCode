#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> majors;   majors.clear();
        map<int,int> mapNums;
        map<int,int>::iterator pos;
        for (int i = 0; i < nums.size(); i++){
            pos = mapNums.find(nums[i]);
            if (pos == mapNums.end()) {
                mapNums.insert(pair<int, int>(nums[i], 1));
                if (nums.size() < 3)
                    majors.push_back(nums[i]);
            }else if (pos->second == nums.size() / 3){
                majors.push_back(pos->first);
                pos->second++;
            }else if (pos->second < nums.size() / 3){
                pos->second++;
            }
        }
        return majors;
    }
};

int main() {
    int a[] = {1};
    vector<int> nums(a,a+1);

    Solution s;
    s.majorityElement(nums);

    return 0;
}