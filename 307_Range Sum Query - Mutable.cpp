#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class MyTreeNode {
public:
	int start, end, sum;
	MyTreeNode *left, *right;
	MyTreeNode(int s, int e, int m = 0) {
		start = s;  end = e;  sum = m;
		left = right = NULL;
	}
};

class NumArray {
public:
    NumArray(vector<int> nums) {
        root = builder(nums, 0, nums.size() - 1);
    }
    
    void update(int i, int val) {
        modify(root, i, val);
    }
    
    int sumRange(int i, int j) {
        return query(root, i, j);
    }

private:
	MyTreeNode *root;

	MyTreeNode* builder(vector<int> const& nums, int start, int end) {
		if (start > end)  return NULL;
		if (start == end)  return new MyTreeNode(start, end, nums[start]);

		MyTreeNode* node = new MyTreeNode(start, end);
		int mid = start + (end - start) / 2;
		node->left  = builder(nums, start, mid);
		node->right = builder(nums, mid + 1, end);
		node->sum = node->left->sum + node->right->sum;
		
		return node;
	}

	int modify(MyTreeNode* node, int i, int val) {
		if (!node)  return 0;
		int diff;
		if (node->start == i && node->end == i) {
			diff = val - node->sum;
			node->sum = val;
			return diff;
		}

		int mid = node->start + (node->end - node->start) / 2;
		if (i <= mid)  diff = modify(node->left, i, val);
		else diff = modify(node->right, i, val);
		node->sum += diff;
		return diff;
	}

	int query(MyTreeNode* node, int i, int j) {
		if (!node)  return 0;
		if (node->start == i && node->end == j)  return node->sum;

		int mid = node->start + (node->end - node->start) / 2;
		if (j <= mid)  return query(node->left, i, j);
		else if (mid + 1 <= i)  return query(node->right, i, j);
		else  return query(node->left, i, mid) + query(node->right, mid + 1, j);
	}
};

int main() {
	vector<int> nums = {1, 3, 5};

	NumArray obj(nums);
	int ans1 = obj.sumRange(0, 2);
	obj.update(1, 2);
	int ans2 = obj.sumRange(0, 2);

	cout << ans1 << " " << ans2 << endl;
	return 0;
}