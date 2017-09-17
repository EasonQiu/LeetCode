#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// https://discuss.leetcode.com/topic/31288/c-o-nlogn-time-o-n-space-mergesort-solution-with-detail-explanation
class Solution { // sort成递减数列容易计算count
public:
    vector<int> countSmaller(vector<int>& nums) { 
        if (nums.empty())  return vector<int>();
        vector<int> ix(nums.size());
        for (int i = 0; i < nums.size(); ++i)  ix[i] = i;
        temp = vector<int>(nums.size());
        ans = vector<int>(nums.size());
        mergeSort(nums, ix, 0, nums.size() - 1);
        return ans;
    }
    
    void mergeSort(vector<int> &nums, vector<int> &ix, int left, int right) {
        if (left >= right)  return;
        int mid = left + (right - left) / 2;
        mergeSort(nums, ix, left, mid);
        mergeSort(nums, ix, mid + 1, right);
        merge(nums, ix, left, mid, right);
    }
    
    void merge(vector<int> &nums, vector<int> &ix, int left, int mid, int right) {
        int i = left, j = mid + 1, k = left;
        while (i <= mid && j <= right) {
            if (nums[ix[i]] > nums[ix[j]]) {
                ans[ix[i]] += right - j + 1;
                temp[k++] = ix[i++];
            } else {
                temp[k++] = ix[j++];
            }
        }
        while (i <= mid)  temp[k++] = ix[i++];
        while (j <= right)  temp[k++] = ix[j++];
        for (int k = left; k <= right; ++k)  ix[k] = temp[k];
    }

private:
    vector<int> temp;
    vector<int> ans;
};

class Solution1 { // segment tree
public:
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.size() == 0)  return vector<int>();
        vector<int> sorted(nums), ans(nums.size());
        unordered_map<int, int> map; // <number, ranking>

        sort(sorted.begin(), sorted.end());
        for (int i = 0; i < nums.size(); ++i)  map[sorted[i]] = i;
        SegNode* root = builder(0, nums.size() - 1);

        for (int i = nums.size() - 1; i >= 0; --i) {
        	ans[i] = count(root, 0, map[nums[i]] - 1);
        	update(root, map[nums[i]], 1);
        }
        return ans;
    }

private:
	class SegNode {
	public:
		int start, end, num;
		SegNode *left, *right;
		SegNode(int s, int e, int n = 0) : start(s), end(e), num(n), left(NULL), right(NULL) {}
	};

	SegNode* builder(int start, int end) {
		if (start == end)  return new SegNode(start, end, 0);
		SegNode* node = new SegNode(start, end, 0);
		int mid = start + (end - start) / 2;
		node->left = builder(start, mid);
		node->right = builder(mid + 1, end);
		return node;
	}

	void update(SegNode* node, int i, int diff) {
		if (!node)  return;
		if (node->start <= i && i <= node->end) {
			node->num += diff;
			update(node->left,  i, diff);
			update(node->right, i, diff);
		}
	}

	int count(SegNode* node, int start, int end) {
		if (!node)  return 0;
		else if (end < node->start || node->end < start)  return 0; // 无重叠
		else if (start <= node->start && node->end <= end)  return node->num; // 全包含
		else return count(node->left, start, end) + count(node->right, start, end); // 部分包含或被包含
	}
};

int main() {
	vector<int> nums = {5, 2, 6, 1};

	Solution2 s;
	vector<int> ans = s.countSmaller(nums);

	for (int n : ans) cout << n << " ";
	cout << endl;
	return 0;
}