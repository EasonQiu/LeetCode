// KMP Substring Search, O(m + n)
// kmp数组的含义是needle[0..i]有多少长度的suffix和prefix是match的
//            j<-j   <-   j        i
//         0  1  2  3  4  5  6  7  8
// needle  a  a  b  a  a  b  a  a  a
// kmp     0  0  0  1  2  3  4  5  2
class Solution { // leetcode 28
public:
    int strStr(string haystack, string needle) {
        if (needle.empty())  return 0;
        if (haystack.empty() || haystack.size() < needle.size())  return -1;
        // init the kmp array
        vector<int> kmp(needle.size());
        int j = 0, i = 1;
        for (; i < needle.size(); ++i) {
            if (needle[i] == needle[j]) {
                kmp[i] = ++j;
            } else {
                while (j > 0 && needle[j] != needle[i])  j = kmp[j - 1];
                kmp[i] = (needle[j] == needle[i]) ? ++j : 0;
            }
        }
        // compare the str
        j = 0;  i = 0;
        while (j < haystack.size()) {
            if (haystack[j] == needle[i]) {
                ++j;  ++i;
                if (i == needle.size())  return j - i;
                // if (i == needle.size()) {  // 如果要找出左右position
                //     pos.push_back(j - i);
                //     i = kmp[i - 1];
                // }
            } else {
                (i > 0) ? i = kmp[i - 1] : ++j;
            }
        }
        // final return
        return -1;
    }
};

class Solution {  // leetcode 214
public:
    string shortestPalindrome(string s) {
        string rev_s(s);
        reverse(rev_s.begin(), rev_s.end());
        string temp = s + '/' + rev_s;
        
        vector<int> kmp(temp.size());
        int j = 0; // index of prefix
        for (int i = 1; i < temp.size(); ++i) {
            if (temp[i] == temp[j]) {
                kmp[i] = ++j;
            } else {
                while (j > 0 && temp[i] != temp[j])  j = kmp[j - 1];
                kmp[i] = (temp[i] == temp[j]) ? ++j : 0;
            }
        }
        
        return rev_s.substr(0, rev_s.size() - kmp.back()) + s;
    }
};


// Multiset
// insert会保证插入元素的相对顺序，即相同值会插入到最后。
// 如果只想erase等于某value的一个元素，则用lower_bound
class Solution { // leetcode 480
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        if (k <= 1)  return vector<double>(nums.begin(), nums.end()); // corner case!
        multiset<int> window(nums.begin(), nums.begin() + k - 1);
        auto mid = next(window.begin(), (k - 1) / 2);
        vector<double> ans;
        for (int i = k - 1; i < nums.size(); ++i) {
            window.insert(nums[i]);
            int erase_num = nums[i - k + 1];
            auto erase_itr = window.lower_bound(erase_num);
            if (window.size() % 2 == 0) {
                if (nums[i] >= *mid)  ++mid;
                ans.push_back((double(*mid) + *prev(mid, 1)) / 2);
                if (erase_num > *mid || erase_itr == mid)  --mid;
            } else {
                if (nums[i] < *mid)  --mid;
                ans.push_back(double(*mid));
                if (erase_num <= *mid)  ++mid;
            }
            // erase in the end cuz mid may be erased!
            window.erase(erase_itr);
        }
        return ans;
    }
};

class MedianFinder { // leetcode 295
public:
    /** initialize your data structure here. */
    MedianFinder() {}
    
    void addNum(int num) {
        stream.insert(num);
        if (stream.size() > 1) {
            if (stream.size() % 2 == 0) {
                if (num >= *mid)  ++mid;
            } else {
                if (num < *mid)  --mid;
            }
        } else {
            mid = stream.begin();
        }
    }
    
    double findMedian() {
        if (stream.size() % 2 == 0) {
            return (double(*mid) + *prev(mid, 1)) / 2;
        } else {
            return double(*mid);
        }
    }
    
private:
    multiset<int> stream;
    multiset<int>::iterator mid;
};

// binary indexed tree
// Extract last bit: i & -i
// 后继：可以理解为节点的父亲节点。是离它最近的，且编号末位连续0比它多的就是它的父亲,如e[2]是e[1]的后继
// 前驱：节点前驱的编号即为比自己小的，最近的，最末连续0比自己多的节点。如e[7]的前驱是e[6],e[6]的前驱是e[4]。
// 计算前驱与后继：
// 　节点e[i]的前驱为 e[i - lowbit(i)];  节点e[i]的后继为 e[i + lowbit(i)]
class NumArray { // leetcode 307
public:
    NumArray(vector<int> nums) {
        vals = nums;
        tree = vector<int>(nums.size() + 1);
        for (int i = 1; i < tree.size(); ++i) {
            int lowbit = i & -i;
            for (int j = i; j > i - lowbit; --j) {
           
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
    
    int sumRange(int i, int j) { // 不应该计算i所以不用++i
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

class NumMatrix { // leetcode 308
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


// segment tree
// 用vector来模拟tree，注意记住计算tree size的公式
// node, left, right同时传入function来表示一个node的相关数据
class NumArray {  // leetcode 307
public:
    NumArray(vector<int> nums) {
        if (nums.empty())  return;
        size = nums.size();
        vals = nums;
        int tree_size = 2 * pow(2, ceil(log(size) / log(2)));  // remember!!
        tree = vector<int>(tree_size);
        buildTree(0, 0, size - 1);
    }
    
    void update(int i, int val) {
        if (size == 0)  return;
        int diff = val - vals[i];
        vals[i] = val;
        int node = 0, left = 0, right = size - 1;
        while (left < right) {
            tree[node] += diff;
            int mid = left + (right - left) / 2;
            if (i <= mid) {
                node = 2 * node + 1;
                right = mid;
            } else {
                node = 2 * node + 2;
                left = mid + 1;
            }
        }
        tree[node] += diff;
    }
    
    int sumRange(int i, int j) {
        if (size == 0)  return 0;
        return queryTree(0, 0, size - 1, i, j);
    }
    
private:
    vector<int> tree;
    vector<int> vals;
    int size = 0;
    
    int buildTree(int node, int left, int right) {
        if (left == right) {
            tree[node] = vals[left];
            return tree[node];
        }
        int mid = left + (right - left) / 2;
        tree[node] = buildTree(2 * node + 1, left, mid) + 
                     buildTree(2 * node + 2, mid + 1, right);
        return tree[node];
    }
    
    int queryTree(int node, int left, int right, const int& low, const int& high) {
        if (high < left || low > right)  return 0;
        if (high >= right && low <= left)  return tree[node];
        int mid = left + (right - left) / 2;
        return queryTree(2 * node + 1, left, mid, low, high) + 
               queryTree(2 * node + 2, mid + 1, right, low, high);
    }
};

// 扫描线算法 Sweep Line


// ---------------------------热门Topic----------------------------------------

// 题意：给定一个数组或字符串，求出值最大或最小的固定长度的subarray
// 解法：维护一个固定长度的stack，只要stack里的元素个数 + 后面剩下的元素个数 >= 固定长度，
//      那么我们就去pop stack里面小于nums[i]的元素
// 例题：402. Remove K Digits   321. Create Maximum Number
int maxSubarray(vector<int> &nums, int len) {
    vector<int> ans(len);  // using like a stack
    int j = 0;  // index of ans
    int size = nums.size();
    for (int i = 0; i < size; ++i) {
        while (j > 0 && j + size - i > k && ans[j - 1] < nums[i]) {
            --j;
        }
        if (j < size)  ans[j++] = nums[i];
    }
    return ans;
}

// 题意：（博弈类问题）先后手只有必胜或必败两种情况，没有可能胜的情况
// 解法：先手必胜 = 子状态存在先手必败，先手必败 = 子状态全为先手必胜
//      DP问题fill the array可以选择对角线填充，或者选择dfs + memorization
// 例题：Coins in a line I II II
class Solution {
public:
    // 两人轮流从一组coins的两端取一个石子，问先手是或否保证values和最大
    // dp[i][j] = sums[i..j] - min(dp[i + 1][j], dp[i][j - 1])
    bool firstWillWin(vector<int> &values) {
        // write your code here
        int size = values.size();
        int dp[size + 1][size + 1];
        int sums[size + 1];
        for (int i = 1; i <= size; ++i) {
            sums[i] = sums[i - 1] + values[i - 1];
        }
        for (int i = size; i >= 1; --i) {
            dp[i][i] = values[i - 1];
            for (int j = i + 1; j <= size; ++j) {
                dp[i][j] = sums[j] - sums[i - 1] - min(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[1][size] > sums[size] / 2;
    }
};
