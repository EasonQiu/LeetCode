#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() <= 0) return false;
        else {
            bool flag = false;
            set<int> mySet;

            for (int i = 0; i < nums.size(); i++){
                if (mySet.find(nums[i]) == mySet.end())  mySet.insert(nums[i]);
                else  flag = true;
                if (flag)  break;
            }

            if (not flag) return false;
            else return true;
        }
    }
};

int main(int argc, char* argv[]) {
    std::vector<int> nums;
    int num;
    string str;

    for (int i = 1; i < argc; i++){
        str = string(argv[i]);
        if (isdigit(str[0])){ // isdigit must be a char, one digit
            num = atoi(str.c_str());
            nums.push_back(num);
        }
    }

    Solution s;
    std::cout << s.containsDuplicate(nums);

    return 0;
}