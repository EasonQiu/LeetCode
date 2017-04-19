#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if ((nums.size() > 1) && (k > 0)){
            k = k % nums.size();
            if (k <= nums.size() / 2) {
                int moveNums = k;
                nums.insert(nums.begin(), nums.end() - moveNums, nums.end());
                nums.erase(nums.end() - moveNums, nums.end());
            }else {
                int moveNums = nums.size() - k;
                nums.insert(nums.end(), nums.begin(), nums.begin() + moveNums);
                nums.erase(nums.begin(), nums.begin() + moveNums);
            }
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
    s.rotate(nums, k);
    for (int i = 0; i < nums.size(); i++)
        std::cout << nums[i] << " ";

    return 0;
}