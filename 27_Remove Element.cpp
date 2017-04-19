#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int find(vector<int>& nums, int val){
        int pos = -1;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == val){
                pos = i; break;
            }
        }
        return pos;
    }

    int removeElement(vector<int>& nums, int val) {
        int ix = find(nums,val);
        int length = nums.size();
        while (ix != -1){
            nums.erase(nums.begin() + ix);
            length--;
            ix = find(nums,val);
        }
        return length;
    }
};

int main() {
    int a[] = {3,2,2,3};
    vector<int> nums(a,a+4);

    Solution s;
    cout << s.removeElement(nums, 3);

    return 0;
}