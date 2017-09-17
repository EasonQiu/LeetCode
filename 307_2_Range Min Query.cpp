#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class NumArray {
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
        modify(0, 0, size - 1, i, val);
    }
    
    int minRange(int i, int j) {
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
        tree[node] = min(construct(nums, 2 * node + 1, left, mid), 
                         construct(nums, 2 * node + 2, mid + 1, right));
        return tree[node];
    }

    int modify(int node, int left, int right, const int &i, const int &val) {
        if (i < left || i > right)  return tree[node];
        if (left == right) {
            tree[node] = val;  
            return tree[node];
        }
        int mid = left + (right - left) / 2;
        tree[node] = min(modify(2 * node + 1, left, mid, i, val),
                         modify(2 * node + 2, mid + 1, right, i, val));
        return tree[node];
    }
    
    int query(int node, int left, int right, const int &bound1, const int &bound2) {
        if (bound1 > right || bound2 < left)  return INT_MAX;
        if (bound1 <= left && bound2 >= right)  return tree[node];
        int mid = left + (right - left) / 2;
        return min(query(2 * node + 1, left, mid, bound1, bound2),
                   query(2 * node + 2, mid + 1, right, bound1, bound2));
    }
};

int main() {
    vector<int> nums = {1, 3, 5};
    NumArray obj(nums);
    cout << obj.minRange(1, 2) << endl;
    obj.update(1, -1);
    cout << obj.minRange(1, 2) << endl;
}