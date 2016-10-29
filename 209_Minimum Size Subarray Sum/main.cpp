#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sum = 0, minLen = nums.size() + 1;
        for (int i = 0; i + 1 < nums.size(); i++){
            sum = nums[i];
            if (sum >= s){
                minLen = 1; break;
            }else {
                for (int j = i + 1; j < nums.size(); j++){
                    sum += nums[j];
                    if (j >= (i + minLen - 1)) break;
                    if (sum >= s){
                        if (j - i + 1 < minLen) minLen = j - i + 1;
                        break;
                    }
                }
            }

        }
        if (minLen == nums.size() + 1) return 0;
        else return minLen;
    }
};

int main() {
    int a[] = {1,2,3,4,5};
    vector<int> nums(a,a+5);

    Solution s;
    cout << s.minSubArrayLen(15,nums);

    return 0;
}