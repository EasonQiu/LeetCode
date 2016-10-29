#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index_notZero = 0;
        for (int i = 0; i != nums.size(); i++){
            if (nums[i] != 0){
                nums[index_notZero++] = nums[i];
            }
        }
        for (int i = index_notZero; i != nums.size(); i++){
            nums[i] = 0;
        }
    }
};

int main(int argc, char* argv[]) {
    std::vector<int> nums;
    int num;
    string str;
    for (int i = 1; i < argc; i++){
        str = string(argv[i]);
        num = atoi(str.c_str());
        nums.push_back(num);
    }


    Solution s;
    s.moveZeroes(nums);

    for (std::vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++)
        std::cout << *iter << " ";
    return 0;
}