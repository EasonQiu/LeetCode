#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty())  return;
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
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