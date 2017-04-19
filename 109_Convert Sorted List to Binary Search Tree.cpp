#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head)  return NULL;
        vector<int> nums;
        while (head != NULL) {
            nums.push_back(head->val);
            head = head->next;
        }
        return binaryIter(nums, 0, nums.size()-1);
    }
    
    TreeNode* binaryIter(const vector<int>& nums, int left, int right){
        int mid = (left + right) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        if (left < mid) node->left = binaryIter(nums, left, mid-1);
        if (mid < right) node->right = binaryIter(nums, mid+1, right);
        return node;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    ListNode* head = new ListNode(0);
    
    Solution s;
    TreeNode *node = s.sortedListToBST(head);
    
    return 0;
}