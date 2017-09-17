// Example:
// Given matrix = [
//   [3, 0, 1, 4, 2],
//   [5, 6, 3, 2, 1],
//   [1, 2, 0, 1, 5],
//   [4, 1, 0, 1, 7],
//   [1, 0, 3, 0, 5]
// ]

// sumRegion(2, 1, 4, 3) -> 8
// update(3, 2, 2)
// sumRegion(2, 1, 4, 3) -> 10

class NumMatrix {  // binary indexed tree
public:
    NumMatrix(vector<vector<int>> matrix) {
        if (matrix.empty() || matrix[0].empty())  return;
        m = matrix.size(), n = matrix[0].size();
        nums = matrix;
        tree = vector<vector<int> >(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; ++i) {
            int lowbit_i = i & -i;
            for (int j = 1; j <= n; ++j) {
                int lowbit_j = j & -j;
                for (int ii = i; ii > i - lowbit_i; --ii) {
                    for (int jj = j; jj > j - lowbit_j; --jj) {
                        tree[i][j] += nums[ii - 1][jj - 1];
                    }
                }
            }
        }
    }
    
    void update(int row, int col, int val) {
        if (m == 0 || n == 0)  return;
        int diff = val - nums[row][col];
        nums[row][col] = val;
        for (int i = row + 1; i <= m; i += i & -i) {
            for (int j = col + 1; j <= n; j += j & -j) {
                tree[i][j] += diff;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (m == 0 || n == 0)  return 0;
        return getSum(row2, col2) + getSum(row1 - 1, col1 - 1) - getSum(row1 - 1, col2) - getSum(row2, col1 - 1);
    }
    
    int getSum(int row, int col) {
        int sum = 0;
        for (int i = row + 1; i >= 1; i -= i & -i) {
            for (int j = col + 1; j >= 1; j -= j & -j) {
                sum += tree[i][j];
            }
        }
        return sum;
    }
    
private:
    int m, n;
    vector<vector<int> > nums, tree;
};

class NumMatrix { // segment tree
public:
    NumMatrix(vector<vector<int>> matrix) {  // O(mn)
        if (matrix.empty())  return;
        mat = matrix;
        m = matrix.size();  n = matrix[0].size();
        int tree_size = 2 * pow(2, ceil(log(n) / log(2))) - 1;
        segtree = vector<vector<int> >(m, vector<int>(tree_size));
        for (int i = 0; i < m; ++i) {
            construct(matrix[i], segtree[i], 0, n - 1, 0);
        }
    }
    
    void update(int row, int col, int val) { // O(logn)
        int diff = val - mat[row][col];
        mat[row][col] = val;
        vector<int> &tree = segtree[row];
        int left = 0, right = n - 1, node = 0;
        while (left < right) {
            tree[node] += diff;
            int mid = left + (right - left) / 2;
            if (col <= mid) {
                right = mid;
                node = 2 * node + 1;
            } else {
                left = mid + 1;
                node = 2 * node + 2;
            }
        }
        tree[node] += diff; // update the leaf node
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) { // O(mlogn)
        int sum = 0;
        for (int i = row1; i <= row2; ++i) {
            sum += query(segtree[i], 0, 0, n - 1, col1, col2);
        }
        return sum;
    }
    
private:
    int m = 0, n = 0;
    vector<vector<int> > segtree;
    vector<vector<int> > mat;
    
    // tree[node] = sum of nums[left...right]
    int construct(vector<int> &nums, vector<int> &tree, int left, int right, int node) {
        if (left == right) { // base case
            tree[node] = nums[left];
            return tree[node];
        }
        int mid = left + (right - left) / 2;
        tree[node] = construct(nums, tree, left, mid, 2 * node + 1) + 
                     construct(nums, tree, mid + 1, right, 2 * node + 2);
        return tree[node];
    }
    
    int query(vector<int> &tree, int node, int left, int right, const int& bound1, const int& bound2) {
        if (bound1 > right || bound2 < left)  return 0;
        if (bound1 <= left && bound2 >= right)  return tree[node];
        int mid = left + (right - left) / 2;
        return query(tree, 2 * node + 1, left, mid, bound1, bound2) + 
               query(tree, 2 * node + 2, mid + 1, right, bound1, bound2);
    }
};