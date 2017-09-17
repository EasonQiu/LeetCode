// 371. Sum of Two Integers (bit manipulation)
class Solution {
public:
    int getSum(int a, int b) {
        if (b == 0)  return a;
        int sum = a ^ b;
        int carry = (a & b) << 1;
        return getSum(sum, carry);
    }
};

// 53. Maximum Subarray
// (2)对于一个有正有负的整数数组,请找出总和最大的连续数列。 
// 给定一个 int 数组 A 和数组大小 n,请返回最大的连续数列的和。保证 n 的 大小小于等于 3000。
int maxSubarraySum(vector<int> &nums) { // O(n)
	int pre_min_sum = 0;
	int cur_sum = 0;
	int max_sum = INT_MIN;  // !!注意初始化的值，因为有负数所以sum可能为负!!
	for (int num : nums) {
		cur_sum += num;
		max_sum = max(max_sum, cur_sum - pre_min_sum);
		pre_min_sum = min(pre_min_sum, cur_sum);
	}
	return max_sum;
}

// 15. 3Sum = 0
class Solution {  // O(n^2)
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() <= 2)  return vector<vector<int> >();
        vector<vector<int> > ans;
        sort(nums.begin(), nums.end());
        int size = nums.size();
        for (int i = 0; i < size - 2; ++i) {
            // corner cases && pruning
            if (i > 0 && nums[i] == nums[i - 1])  continue;
            if (nums[i] + nums[i + 1] + nums[i + 2] > 0)  break;
            if (nums[i] + nums[size - 2] + nums[size - 1] < 0)  continue;
            // two pointers to find the solution
            int left = i + 1, right = size - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    ans.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    ++left;
                    while (left < right && nums[left] == nums[left - 1])  ++left;
                } else if (sum < 0) {
                    ++left;
                    while (left < right && nums[left] == nums[left - 1])  ++left;
                } else {
                    --right;
                    while (left < right && nums[right] == nums[right + 1])  --right;
                }
            }
        }
        return ans;
    }
};

// 139. Word Break
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> valid_index = {-1};
        for (int i = 0; i < s.size(); ++i) {
            for (int j : valid_index) {
                if (dict.find(s.substr(j + 1, i - j)) != dict.end()) {
                    valid_index.push_back(i);
                    break;
                }
            }
        }
        return valid_index.back() + 1 == s.size();
    }
};

// 140. Word Break II
// find all solutions
class Solution { // DP + Backtracking
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<vector<int> > dp(s.size());
        vector<int> valid_index = {-1};
        for (int i = 0; i < s.size(); ++i) {
            for (int j : valid_index) {
                if (dict.find(s.substr(j + 1, i - j)) != dict.end()) {
                    dp[i].push_back(j);
                }
            }
            if (!dp[i].empty())  valid_index.push_back(i);
        }
        vector<string> ans;
        vector<string> words;
        dfs(dp, s, s.size() - 1, words, ans);
        return ans;
    }
    
    void dfs(vector<vector<int> > &dp, string &s, int i, vector<string> &words, vector<string> &ans) {
        if (i == -1) { // base case
            int size = words.size();
            string sol = words.back();
            for (int k = size - 2; k >= 0; --k)  sol += " " + words[k];
            ans.push_back(sol);
        } else { // normal case
            for (int j : dp[i]) {
                words.push_back(s.substr(j + 1, i - j));
                dfs(dp, s, j, words, ans);
                words.pop_back();
            }
        }
    }
};

// 91. Decode Ways
// A->Z: 1->26, 一串字符有多少解码方式
class Solution { // DP
public:
    int numDecodings(string s) {
    	if (s.empty() || s[0] == '0')  return 0;
        vector<int> dp(s.size() + 1);
        dp[0] = 1;  dp[1] = 1;
        for (int i = 2; i <= s.size(); ++i) {
        	if (s[i - 1] == '0') {
                cout << s[i - 2] << " ";
        		if (s[i - 2] != '1' && s[i - 2] != '2')  return 0; // !!不要写错逻辑&&!!
        		dp[i] = dp[i - 2];
        	} else {
        		dp[i] = dp[i - 1];
        		if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')) {
        			dp[i] += dp[i - 2];
        		}
        	}
        }
        return dp[s.size()];
    }
};

// (7)有一个排过序的没有字符串数组,但是其中有插入了一些空字符串, 请设计一个算法,找出给定字符串的位置。
// 算法的查找部分的复杂度应该为 log 级别。
// 给定一个 string 数组 str,同时给定数组大小 n 和需要查找的 string x,请 返回该串的位置(位置从零开始)。
int findString(vector<string> &strs, string &target) {
	if (strs.empty() || target.empty())  return -1;
	int left = 0;
	int right = strs.size() - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		int copy = mid;
		while (left <= mid && strs[mid] == "")  --mid;
		if (mid < left) {
			mid = copy + 1;
			while (mid <= right && strs[mid] == "")  ++mid;
			if (mid > right)  return -1;
		}
		if (strs[mid] == target) {
			return mid;
		} else if (strs[mid] > target) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	return -1;
}

// !!(8)现在我们要读入一串数,同时要求在读入每个数的时候算出它的秩,即在当前数组中小于等于它的数的个数(不包括它自身),
// 请设计一个高效的数据结构和算法来实现这个功能。
// 给定一个 int 数组 A,同时给定它的大小n,请返回一个 int 数组,元素为每次加入的数的秩。
// 保证数组 大小小于等于 5000。
vector<int> getRankOfNumber(vector<int> &nums) {  // O(n^2) 搜索的时候可以用binary search
	if (nums.empty())  return vector<int>();
	vector<int> ans(nums.size());
	vector<int> rolling;
	for (int i = 0; i < nums.size(); ++i) {
		int j = 0;
		while (j < i && nums[j] <= nums[i])  ++j;  // 可以用二分查找
		rolling.insert(rolling.begin() + j, nums[i]);
		ans[i] = j;
	}
	return ans;
}

// 209. Minimum Size Subarray Sum
// 找出和大于等于sum的最小长度连续子数组
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
    	int min_len = INT_MAX;
    	int left = 0;
    	int rolling_sum = 0;
    	for (int right = 0; right < nums.size(); ++right) {
    		rolling_sum += nums[right];
    		while (rolling_sum >= s) {
    			min_len	= min(min_len, right - left + 1);
    			rolling_sum -= nums[left++];
    		}
    	}
    	return (min_len == INT_MAX) ? 0 : min_len;
    }
};

// 349. Intersection of Two Arrays
// Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        vector<int> ans;
        for (int num : nums2) {
            if (set1.find(num) != set1.end()) {
                ans.push_back(num);
                set1.erase(num);
            }
        }
        return ans;
    }
};

// 350. Intersection of Two Arrays II
// Each element in the result should appear as many times as it shows in both arrays.
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map; // <number, count>
        for (int num : nums1)  ++map[num];
        vector<int> ans;
        for (int num : nums2) {
        	auto pos = map.find(num);
        	if (pos != map.end()) {
        		if (--pos->second >= 0)  ans.push_back(num);
        	}
        }
        return ans;
    }
};

// 75. Sort Colors
class Solution {
public:
    void sortColors(vector<int>& nums) {
    	if (nums.size() <= 1)  return;
        int left = 0; 
        int right = nums.size() - 1;
        int i = 0;
        while (i <= right) {
        	if (nums[i] == 0) {
        		swap(nums[left++], nums[i++]);
        	} else if (nums[i] == 2) {
        		swap(nums[right--], nums[i]);
        	} else {
        		i++;
        	}
        }
    }
};

// 121. Best Time to Buy and Sell Stock
// 只允许交易一次
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1)  return 0;
        int max_profit = 0;
        int pre_min = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            max_profit = max(max_profit, prices[i] - pre_min);
            pre_min = min(pre_min, prices[i]);
        }
        return max_profit;
    }
};

// 122. Best Time to Buy and Sell Stock II
// 允许多次交易
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1)  return 0;
        int profit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i - 1])  profit += prices[i] - prices[i - 1];
        }
        return profit;
    }
};

// 33. Search in Rotated Sorted Array (No duplicates)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty())  return -1;
        int left = 0;
        int right = nums.size() - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (target == nums[mid])  return mid;
            if (nums[left] < nums[mid] && nums[mid] > nums[right]) { // 2 3 1
                (nums[left] <= target && target < nums[mid]) ? right = mid : left = mid;
            } else if (nums[left] > nums[mid] && nums[mid] < nums[right]) { // 3 1 2
                (nums[mid] < target && target <= nums[right]) ? left = mid : right = mid;
            } else { // 1 2 3
                (target < nums[mid]) ? right = mid : left = mid;
            }
        }
        return (nums[left] == target) ? left : (nums[right] == target) ? right : -1;
    }
};

// 81. Search in Rotated Sorted Array II (duplicates)
// corner cases: 2 2 1 2 2 2 2 2 2 2 2 
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty())  return false;
        int left = 0;
        int right = nums.size() - 1;
        while (left + 1 < right) {
        	int mid = left + (right - left) / 2;
        	if (target == nums[mid])  return true;
        	if (nums[left] == nums[mid] && nums[mid] == nums[right]) { // 2 2 2
        		++left;  --right;  continue;
        	}
        	if (nums[left] <= nums[mid] && nums[mid] > nums[right]) { // 2/3 3 1
        		(nums[left] <= target && target < nums[mid]) ? right = mid : left = mid;
        	} else if (nums[left] > nums[mid] && nums[mid] <= nums[right]) { // 3 1 1/2
        		(nums[mid] < target && target <= nums[right]) ? left = mid : right = mid;
        	} else { // 1 2 3
        		(target < nums[mid]) ? right = mid : left = mid;
        	}
        }
        if (nums[left] == target || nums[right] == target)  return true;
        return false;
    }
};

// 70. Climbing Stairs变形
// 一次可以走1~3步
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2)  return n;
        long dp[n + 1] = {};
        dp[0] = 1;  dp[1] = 1;  dp[2] = 2;
        for (int i = 3; i <= n; ++i) {
            dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
            dp[i] %= 1000000007;
        }
        return dp[n];
    }
};

// 63. Unique Paths II
// 矩形网格从左上到右下的path数，有障碍
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size(), col = obstacleGrid[0].size();
        vector<vector<int> > dp(row, vector<int>(col));
        // base case
        for (int j = 0; j < col; ++j) {
            if (obstacleGrid[0][j] == 1)  break;
            dp[0][j] = 1;
        }
        for (int i = 0; i < row; ++i) {
            if (obstacleGrid[i][0] == 1)  break;
            dp[i][0] = 1;
        }
        // fill the array
        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                if (obstacleGrid[i][j] == 1)  continue;
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        // final answer
        return dp[row - 1][col - 1];
    }
};

// (17)在数组 A[0..n-1]中,有所谓的魔术索引,满足条件 A[i]=i。给定一个升序数组,元素
// 值各不相同,编写一个方法,判断在数组 A 中是否存在魔术索引。请思考一种复杂度优于 o(n)的方法。 
// 给定一个 int 数组 A 和 int n 代表数组大小,请返回一个 bool,代表是否存在魔术索引。
bool findMagicIndex(vector<int> &A) { // i < A[i],go left; i > A[i], go right
	if (A.empty())  return false;
	int left = 0; 
	int right = A.size() - 1;
	while (left < right) {
		int mid = left + (right - left) / 2;
		if (mid == A[mid])  return true;
		if (mid < A[mid]) {
			right = mid;
		} else {
			left = mid + 1;
		}
	}
	if (left == A[left])  return true;
	return false;
}

// 38. Count and Say
class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)  return "1";
        string ans = "1";
        while (--n > 0) {
            string pre = ans;
            ans = "";
            int i = 0, count = 1;
            while (i < pre.size()) {
                while (i + 1 < pre.size() && pre[i + 1] == pre[i]) {
                    ++i;  ++count;
                }
                ans += to_string(count) + pre[i];
                ++i;  count = 1;
            }
        }
        return ans;
    }
};

// 211. Add and Search Word - Data structure design
#define ALPHABET_SIZE 26

class TrieNode {
public:
  TrieNode* child_nodes[ALPHABET_SIZE];
  char val;
  bool is_leaf;
  // Initialize your data structure here.
  TrieNode() : val('/'), is_leaf(false) {
    for (int i = 0; i < ALPHABET_SIZE; ++i)  child_nodes[i] = NULL;
  }
  TrieNode(char val_) : val(val_), is_leaf(false) {
    for (int i = 0; i < ALPHABET_SIZE; ++i)  child_nodes[i] = NULL;
  }
};

class WordDictionary {
public:
  WordDictionary() {
    root = new TrieNode();
  }

  // Inserts a word into the WordDictionary.
  void addWord(string word) {
    int index;
    TrieNode *crawl = root;
    for (int level = 0; level < word.size(); ++level) {
      index = word[level] - 'a';
      if (!crawl->child_nodes[index]) {
        crawl->child_nodes[index] = new TrieNode(word[level]);
      }
      crawl = crawl->child_nodes[index];
    }
    crawl->is_leaf = true;
  }

  // Returns if the word is in the WordDictionary.
  bool search(string word) {
    return searchHelper(word, root, 0);
  }

  bool searchHelper(const string &word, TrieNode *crawl, int level) {
    if (level == word.size())  return crawl->is_leaf;
    if (word[level] == '.') {
      for (int i = 0; i < ALPHABET_SIZE; ++i) {
        if (crawl->child_nodes[i]) {
          if (searchHelper(word, crawl->child_nodes[i], level + 1))
            return true;
        }
      }
      return false;
    } else {
      int index = word[level] - 'a';
      if (!crawl->child_nodes[index]) {
        return false;
      } else {
        return searchHelper(word, crawl->child_nodes[index], level + 1);
      }
    }
  }

  // Returns if there is any word in the WordDictionary
  // that starts with the given prefix.
  bool startsWith(string prefix) {
    int index;
    TrieNode *crawl = root;
    for (int level = 0; level < prefix.size(); ++level) {
      index = prefix[level] - 'a';
      if (!crawl->child_nodes[index])  return false;
      crawl = crawl->child_nodes[index];
    }
    if (crawl->is_leaf)  return true;
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
      if (crawl->child_nodes[i])  return true;
    }
    return false;
  }

private:
  TrieNode* root;
};

// 283. Move Zeroes
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0)  nums[j++] = nums[i];
        }
        while (j < nums.size())  nums[j++] = 0;
    }
};

// 215. Kth Largest Element in an Array
class Solution { // nlogk, priority queue
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (k < 0 || k > nums.size())  return INT_MIN;
        priority_queue<int, vector<int>, greater<int> > pq;
        for (int num : nums) {
            if (pq.size() == k) {
                if (num > pq.top()) {
                    pq.pop();
                    pq.push(num);
                }
            } else {
                pq.push(num);
            }
        }
        return pq.top();
    }
};
class Solution { // binary search
public:
    int findKthLargest(vector<int>& nums, int k) { // 递减数列中排k-1
        if (k < 0 || k > nums.size())  return INT_MIN;
        --k;
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            // partition
            int pivot = nums[right];
            int large = left;
            for (int i = left; i < right; ++i) {
                if (nums[i] > pivot)  swap(nums[large++], nums[i]);
            }
            swap(nums[large], nums[right]);
            // check
            if (k == large) {
                return nums[large];
            } else if (k < large) {
                right = large - 1; // !!注意要加减
            } else {
                left = large + 1;
            }
        }
    }
};
 
// 114. Flatten Binary Tree to Linked List
// careful to the pointers
class Solution {
public:
    void flatten(TreeNode* root) {
        helper(root);
    }
    
    void helper(TreeNode* node) {
        if (!node)  return;
        last = node;
        // flatten left subtree
        helper(node->left);
        // process node
        if (node->left) {
            last->right = node->right;
            node->right = node->left;
            node->left = NULL;
        }
        // flatten right subtree
        helper(last->right); 
    }

private:
    TreeNode* last = NULL;
};

// !!(23)有数量不限的硬币,币值为 25 分、10 分、5 分和 1 分,请编写代码计算 n 分有 几种表示法。
// 给定一个 int n,请返回 n 分有几种表示法。
// !!注意这和阶梯走法有不同，这边151和115是重复的，认为一种解法
class Solution {
public:
    int coinChange(int amount) {
    	if (amount <= 0)  return 0;
    	int coins[4] = {1, 5, 10, 25};
        int dp[amount + 1] = {};
        dp[0] = 1;
        for (int denomi : coins) {
            for (int i = denomi; i <= amount; ++i) {
                dp[i] += dp[i - denomi];
            }
        }
        return dp[amount];
    }
};

// 278. First Bad Version
// Forward declaration of isBadVersion API.
class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

// 155. Min Stack
// method1: 两个stack存val和min
// method2: 两个vector存val和min_index, 一个为单调递减栈
// method3: 每次如果最小值改变，则将min插入stack中
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int x) {
        if (x <= min) {
            mystack.push(min);
            min = x;
        }
        mystack.push(x);
    }
    
    void pop() {
        if (mystack.top() == min)  {
            mystack.pop();
            min = mystack.top();
        }
        mystack.pop();
    }
    
    int top() {
        return mystack.top();
    }
    
    int getMin() {
        return min;
    }

private:
    int min = INT_MAX;
    stack<int> mystack;
};

// 62. Unique Paths
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> rows(n, 1);
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                rows[j] = rows[j - 1] + rows[j];
            }
        }
        return rows[n - 1];
    }
};

// 17. Letter Combinations of a Phone Number
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty())  return vector<string>();
        vector<string> ans;
        string str(digits.size(), 'a');
        dfs(digits, 0, str, ans);
        return ans;
    }
    
    void dfs(string &digits, int i, string &str, vector<string> &ans) {
        if (i == digits.size()) {
            ans.push_back(str);
            return;
        }
        string letters = map[digits[i] - '2'];
        for (int k = 0; k < letters.size(); ++k) {
            str[i] = letters[k];
            dfs(digits, i + 1, str, ans);
        }
    }

private:
    string map[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
};

// 200. Number of Islands
// DFS / Union Find
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty())  return 0;
        row = grid.size();
        col = grid[0].size();
        int count = 0;
        parent = vector<int>(row * col);
        // init the parent
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == '0')  continue;
                parent[i * col + j] = i * col + j;
                ++count;
            }
        }
        // union islands
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == '0')  continue;
                if (i + 1 < row && grid[i + 1][j] == '1' && finds(i * col + j) != finds((i + 1) * col + j)) {
                    unions(i, j, i + 1, j);
                    --count;
                }
                if (j + 1 < col && grid[i][j + 1] == '1' && finds(i * col + j) != finds(i * col + j + 1)) {
                    unions(i, j, i, j + 1);
                    --count;
                }
            }
        }
        return count;
    }
    
    int finds(int index) {
        while (index != parent[index]) {
            parent[index] = parent[parent[index]];
            index = parent[index];
        }
        return index;
    }
    
    void unions(int i1, int j1, int i2, int j2) {
        parent[finds(i1 * col + j1)] = finds(i2 * col + j2);
    }
    
private:
    int row;
    int col;
    vector<int> parent;
};

// 128. Longest Consecutive Sequence
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() <= 1)  return nums.size();
        unordered_map<int, int> map;  // <num, len>
        int max_len = 1;
        for (int num : nums) {
            if (map.find(num) != map.end())  continue;
            int len1 = map.find(num - 1) == map.end() ? 0 : map[num - 1];
            int len2 = map.find(num + 1) == map.end() ? 0 : map[num + 1];
            int len = len1 + len2 + 1;
            map[num] = len;  map[num - len1] = len;  map[num + len2] = len;
            max_len = max(max_len, len);
        }
        return max_len;
    }
};

// (31)给定 n 对括号,请写一个函数以将其生成新的括号组合,并返回所有组合结果
vector<string> generateParenthesis(int n) {
    vector<string> ans;
    string paren(2 * n, ' ');
    if (n <= 0)  return ans;
    helper(n, n, 0, paren, ans);
    return ans;
}

void helper(int left, int right, int i, string &paren, vector<string> &ans) {
    if (i == paren.size()) {
        ans.push_back(paren);  return;
    }
    if (left > 0) {
        paren[i] = '(';
        helper(left - 1, right, i + 1, paren, ans);
    }
    if (left < right) {
        paren[i] = ')';
        helper(left, right - 1, i + 1, paren, ans);
    }
}

// 98. Validate Binary Search Tree
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return check(root, prev);
    }
    
    bool check(TreeNode* node, TreeNode* &prev) {
        if (!node)  return true;
        if (!check(node->left, prev))  return false;
        if (prev && prev->val >= node->val)  return false;
        prev = node;
        return check(node->right, prev);
    }
};

// 78. Subsets
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int> comb;
        dfs(nums, 0, comb, ans);
        return ans;
    }
    
    void dfs(vector<int> &nums, int i, vector<int> &comb, vector<vector<int> > &ans) {
        if (i == nums.size()) {
            ans.push_back(comb);
            return;
        }
        dfs(nums, i + 1, comb, ans);
        comb.push_back(nums[i]);
        dfs(nums, i + 1, comb, ans);
        comb.pop_back();
    }
};

// 90. Subsets II
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &nums) {
        vector<vector<int> > answer;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        helper(nums, answer, subset, 0);
        return answer;
    }
    
    void helper(vector<int> const &nums, vector<vector<int> > &answer,
                vector<int> &subset, int index) {
        // finish creating one subset, push it into answer
        if (index == nums.size()) {
            answer.push_back(subset);  return;
        }
        // count the number of duplicates of this number
        int k = index + 1;  // the index of the first number that is not a duplicate
        while (k < nums.size() && nums[k] == nums[k - 1]) ++k;
        // (k-index) means the number of duplicates
        for (int i = 0; i <= k - index; ++i)  subset.push_back(nums[index]);
        for (int i = 0; i <= k - index; ++i) {
            subset.pop_back();
            helper(nums, answer, subset, k);
        }
    }
};

// 52. N-Queens II
class Solution {
public:
    int totalNQueens(int n) {
        vector<bool> col(n), plus(2 * n), minus(2 * n);
        int count = 0;
        dfs(col, plus, minus, 0, count, n);
        return count;
    }
    
    void dfs(vector<bool> &col, vector<bool> &plus, vector<bool> &minus, int i, int &count, int &n) {
        if (i == n) {
            ++count;  return;
        }
        for (int j = 0; j < n; ++j) {
            if (!col[j] && !plus[i + j] && !minus[i - j + n]) {
                col[j] = true;  plus[i + j] = true;  minus[i - j + n] = true;
                dfs(col, plus, minus, i + 1, count, n);
                col[j] = false;  plus[i + j] = false;  minus[i - j + n] = false;
            }
        }
    }
};

// 285. Inorder Successor in BST
// 找到大于p->val的节点中最小的那个
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* succ = NULL;
        while (root) {
            if (p->val >= root->val) {
                root = root->right;
            } else if (p->val < root->val) {
                succ = root;
                root = root->left;
            }
        }
        return succ;
    }
};

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* prev = NULL;
        return traverse(root, p, prev);
    }
    
    TreeNode* traverse(TreeNode* node, TreeNode* p, TreeNode* &prev) {
        if (!node)  return NULL;
        TreeNode* right = traverse(node->right, p, prev);
        if (right)  return right;
        if (node == p)  return prev;
        prev = node;
        return traverse(node->left, p, prev);
    }
};

// 161. One Edit Distance
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int len1 = s.size(), len2 = t.size();
        if (abs(len1 - len2) > 1)  return false;
        int i = 0, j = 0;
        int distance = false;
        for (;i < len1 && j < len2; ++i, ++j) {
            if (s[i] == t[j])  continue;
            if (++distance > 1)  return false;
            if (len1 != len2) {
                (len1 < len2) ? --i : --j;
            }
        }
        if (i != len1 || j != len2)  ++distance; // one letter not compared
        return (distance == 1) ? true : false;
    }
};

// 7. Reverse Integer
// c++负数整除的商和余数均永远<=0，相当于整数加个符号
class Solution {
public:
    int reverse(int x) {
        long ans = 0;
        while (x) {
            ans = ans * 10 + x % 10;
            x = x / 10;
        }
        return (ans < INT_MIN || ans > INT_MAX) ? 0 : (int)ans;
    }
};

// (39)给定一个字符串,验证其是否为数字。
// 注意去除头尾空格，+-号，.号，科学计数法e

// 232. Implement Queue using Stacks
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {}
    
    /** Push element x to the back of queue. */
    void push(int x) {
        input.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int val = peek();
        output.pop();
        return val;
    }
    
    /** Get the front element. */
    int peek() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return input.empty() && output.empty();
    }
    
private:
    stack<int> input;
    stack<int> output;
};

// 315. Count of Smaller Numbers After Self
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

// 111. Minimum Depth of Binary Tree
class Solution { // DFS
public:
    int minDepth(TreeNode* root) {
        if (!root)  return 0;
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        if (left == 0 || right == 0)  return left + right + 1;
        return min(left, right) + 1;
    }
};

