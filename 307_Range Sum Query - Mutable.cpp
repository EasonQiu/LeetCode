#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class NumArray { // binary indexed tree
public:
    NumArray(vector<int> nums) {
        vals = nums;
        tree = vector<int>(nums.size() + 1);
        for (int i = 1; i < tree.size(); ++i) {
            int lowbit = i & -i;
            for (int j = i; j > i - lowbit; --j) {
                tree[i] += nums[j - 1];
            }
        }
    }
    
    void update(int i, int val) {
        int diff = val - vals[i];
        vals[i] = val;
        for (++i; i < tree.size(); i += i & -i) {
            tree[i] += diff;
        }
    }
    
    int sumRange(int i, int j) {
        int sum1 = 0, sum2 = 0;
        while (i) {
            sum1 += tree[i];
            i -= i & -i;
        }
        ++j;
        while (j) {
            sum2 += tree[j];
            j -= j & -j;
        }
        return sum2 - sum1;
    }
    
private:
    vector<int> tree, vals;
};


class NumArray { // segment tree
public:
    NumArray(vector<int> nums) {
        size = nums.size();
        if (size == 0)  return;
        number = nums;
        int tree_size = 2 * pow(2, ceil(log(size) / log(2))) + 1;
        tree = vector<int>(tree_size);
        construct(nums, 0, 0, size - 1);
    }
    
    void update(int i, int val) {
        if (size == 0)  return;
        int diff = val - number[i];
        number[i] = val;
        int left = 0, right = size - 1, node = 0;
        while (left < right) {
            tree[node] += diff;
            int mid = left + (right - left) / 2;
            if (i <= mid) {
                right = mid;
                node = 2 * node + 1;
            } else {
                left = mid + 1;
                node = 2 * node + 2;
            }
        }
        tree[node] += diff;
    }
    
    int sumRange(int i, int j) {
        return query(0, 0, size - 1, i, j);
    }

private:
    int size;
    vector<int> number;
    vector<int> tree;
    
    int construct(vector<int> &nums, int node, int left, int right) {
        if (left == right) {
            tree[node] = nums[left];
            return tree[node];
        }
        int mid = left + (right - left) / 2;
        tree[node] = construct(nums, 2 * node + 1, left, mid) + 
                     construct(nums, 2 * node + 2, mid + 1, right);
        return tree[node];
    }
    
    int query(int node, int left, int right, int bound1, int bound2) {
        if (bound1 > right || bound2 < left)  return 0;
        if (bound1 <= left && bound2 >= right)  return tree[node];
        int mid = left + (right - left) / 2;
        return query(2 * node + 1, left, mid, bound1, bound2) + 
               query(2 * node + 2, mid + 1, right, bound1, bound2);
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