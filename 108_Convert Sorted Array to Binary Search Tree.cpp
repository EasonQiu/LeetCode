#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0)  return NULL;
        return binaryIter(nums, 0, nums.size()-1);
    }
    
    TreeNode* binaryIter(const vector<int>& nums, int left, int right){
        int mid = (left + right) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        if (left < mid) node->left = binaryIter(nums, left, mid-1);
        else node->left = NULL;
        if (mid < right) node->right = binaryIter(nums, mid+1, right);
        else node->right = NULL;
        return node;
    }
};

int main() {
    int arr[] = {1,2,3,4,5,6,7};
    vector<int> nums(arr, arr+7);
    
    Solution s;
    TreeNode* node = s.sortedArrayToBST(nums);
    
    return 0;
}