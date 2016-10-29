#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if ( (nums.size() <= 0) || (k <= 0))
            return false;
        else {
            bool flag = false;
            set<int> mySet;

            // solve the situation when k > nums.size() - 1
            if (k >= nums.size() - 1)
                k = nums.size() - 1;

            // check the first k numbers
            for (int i = 0; i <= k; i++){
                // not found, then insert
                if (mySet.find(nums[i]) == mySet.end())
                    mySet.insert(nums[i]);
                else
                    flag = true;
                // found, then exit
                if (flag) break;
            }

            // check the left numbers
            if (not flag){
                int leftIndex = 0;
                int rightIndex = k + 1;
                while ((not flag) && (rightIndex <= nums.size() -1)){
                    // judge whether rightIndex equals to all the previous
                    mySet.erase(nums[leftIndex++]);
                    if (mySet.find(nums[rightIndex]) == mySet.end())
                        mySet.insert(nums[rightIndex]);
                    else
                        flag = true;

                    // still not found, then move to next index
                    if (not flag) rightIndex++;
                }
            }

            // return false when not find
            if (not flag)
                return false;
            else
                return true;
        }
    }
};

int main(int argc, char* argv[]) {
    std::vector<int> nums;
    int num, k;
    string str(argv[1]);
    k = atoi(str.c_str());
    for (int i = 2; i < argc; i++){
        str = string(argv[i]);
        if (isdigit(str[0])){ // isdigit must be a char, one digit
            num = atoi(str.c_str());
            nums.push_back(num);
        }
    }

    Solution s;
    std::cout << s.containsNearbyDuplicate(nums, k);

    return 0;
}