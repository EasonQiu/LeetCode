// Right Rotation

// 89. Gray Code
class Solution {
public:
    vector<int> grayCode(int n) {
        if (n < 0)  return vector<int>();
        vector<int> ans = {0};
        for (int k = 0; k < n; ++k) {
            for (int i = ans.size() - 1; i >= 0; --i) {
                ans.push_back(ans[i] | (1 << k));
            }
        }
        return ans;
    }
};

// 338. Counting Bits (按题目意思更接近这道)
// 原题意思是：统计两个int的二进制表达方式上数值不同的位数
class Solution { // Bit manipulation
public:
    vector<int> countBits(int num) {
        vector<int> ans(num + 1);
        for (int i = 1; i <= num; ++i) {
            int val = i;
            while (val) {
                val &= val - 1;
                ++ans[i];
            }
        }
        return ans;
    }
};

class Solution { // DP
public:
  vector<int> countBits(int num) {
  	vector<int> dp(num + 1);
  	for (int i = 1; i <= num; ++i) {
  		dp[i] = dp[i >> 1] + (i & 1);
  	}
  	return dp;
  }
};

// remove vowels in string
string removeVowel(string &s) {
	string ans = "";
	string vowel = "aeiouAEIOU";
	for (char ch : s) {
		if (vowel.find(ch) == vowel.npos)  ans += ch;
	}
	return ans;
}

// 20. Valid Parentheses (原题只包含(),并要求pair的个数)
int countValidParentheses(string s) {
	int stack = 0;
	for (char ch : s) {
		stack += (ch == '(') ? 1 : -1;
		if (stack < 0)  return -1;
	}
	return (stack == 0) ? s.size() / 2 : -1;
}

// 5. Longest Palindromic Substring
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1)  return s;
        start = 0;  max_len = 1;
        for (int i = 0; i < s.size(); ++i) {
            extend(s, i, i);
            extend(s, i, i - 1);
        }
        return s.substr(start, max_len);
    }
    
    void extend(string &s, int i, int j) {
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            --i;  ++j;
        }
        if (j - i - 1 > max_len) {
            start = i + 1;
            max_len = j - i - 1;
        }
    }
    
private:
    int start;
    int max_len;
};

// 409. Longest Palindrome
class Solution {
public:
    int longestPalindrome(string s) {
        int dict[128] = {}; // <char, count>
        for (char ch : s)  ++dict[ch];
        int odds = 0;
        for (int count : dict) {
            if (count & 1)  ++odds;
        }
        return s.size() - odds + (odds > 0 ? 1 : 0);
    }
};

// 21. Merge Two Sorted Lists
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *node = dummy;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                node->next = l1;
                node = node->next;
                l1 = l1->next;
            } else {
                node->next = l2;
                node = node->next;
                l2 = l2->next;
            }
        }
        if (l1)  node->next = l1;
        if (l2)  node->next = l2;
        return dummy->next;
    }
};

// 234. Palindrome Linked List (用到reverse second half)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)  return true;
        // find the medium node
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        // reverse the second half
        ListNode* curr = slow->next;
        ListNode* prev = NULL;
        ListNode* next;
        while (curr) {
            next = curr->next;  curr->next = prev;
            prev = curr;  curr = next;
        }
        // compare
        ListNode* n1 = head;
        ListNode* n2 = prev;
        while (n2) {
            if (n1->val != n2->val)  return false;
            n1 = n1->next;  n2 = n2->next;
        }
        return true;
    }
};

// 206. Reverse Linked List (接近原题)
class Solution { // recursion
public:
    ListNode* reverseList(ListNode* head) {
        return reverse(head, NULL);
    }
    
    ListNode* reverse(ListNode* curr, ListNode* prev) {
        if (!curr)  return prev;  // new head node
        ListNode* next = curr->next;
        curr->next = prev;
        return reverse(next, curr);
    }
};

// 572. Subtree of Another Tree
class Solution {
 public:
  bool isSubtree(TreeNode* s, TreeNode* t) {
    // base case
    if (!s && !t)  return true;
    if (!s || !t)  return false;
    // check if tree t is the same as tree s
    return isSame(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
  }

  bool isSame(TreeNode *s, TreeNode *t) {
    if (!s && !t)  return true;
    if (!s || !t)  return false;
    if (s->val != t->val)  return false;
    return isSame(s->left, t->left) && isSame(s->right, t->right);
  }
};

// Two Sum Count
class Solution {
public:
  int twoSumCount(vector<int>& nums, int target) {
    unordered_map<int, int> map; // <number, count>
    int count = 0;
    for (int num : nums) {
    	if (map.find(target - num) != map.end()) {
    		count += map[target - num];
    	}
    	++map[num];
    }
    return count;
  }
};

// !!!Find K Nearest Point
struct Point {
    int x, y;
    Point(int x_, int y_) : x(x_), y(y_) {}
};

double distance(Point &p1, Point &p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

class pqCompare {
public:
    bool operator() (pair<double, Point> &lhs, pair<double, Point> &rhs) {
        return lhs.first < rhs.first;
    }
};

vector<Point> kNearestPoint(vector<Point> &points, Point origin, int k) {
    priority_queue<pair<double, Point>, vector<pair<double, Point> >, pqCompare> pq;
    for (Point &p : points) {
        pq.push(make_pair(distance(p, origin), p));
        if (pq.size() > k)  pq.pop();
    }
    vector<Point> ans;
    while (!pq.empty()) {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}

// Overlap Rectangle
// 给两个长方形的 topLeft 和 bottomRight 坐标, 判断这两个长方形是否重叠
// 有一条边重叠也算重叠，所以没有=号
bool doOverlap(Point l1, Point r1, Point l2, Point r2) {
	if (r1.x < l2.x || l1.x > r2.x)  return false;
	if (r1.y > l2.y || l1.y < r2.y)  return false;
	return true;
}

// 223. Rectangle Area (类似overlap rectangle)
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area = (C - A) * (D - B) + (G - E) * (H - F);
        if (C <= E || A >= G)  return area;
        if (B >= H || D <= F)  return area;
        return area - (min(C, G) - max(A, E)) * (min(D, H) - max(B, F));
    }
};

// window sum
vector<int> sumOfWindow(vector<int> &nums, int k) {
	if (nums.size() < k || k <= 0)  return vector<int>();
	vector<int> ans(nums.size() - k + 1);
	for (int i = 0; i < k; ++i) {
		ans[0] += nums[i];
	}
	for (int i = 1; i < ans.size(); ++i) {
		ans[i] = ans[i - 1] - nums[i - 1] + nums[i + k - 1];
	}
	return ans;
}

// Greatest Common Divisor 求一个数组的最大公约数
// corner cases: 0
int gcdOfArray(vector<int> &nums) {
	if (nums.size() <= 1)  return 0;
	int ans = nums[0];
	for (int i = 1; i < nums.size(); ++i) {
		ans = gcd(ans, nums[i]);
	}
	return ans;
}

int gcd(int n1, int n2) {
	if (n1 == 0 || n2 == 0)  return 0; 
	if (n2 > n1)  swap(n1, n2);
	while (n2) {
		int remain = n1 % n2;
		n1 = n2;  n2 = remain;
	}
	return n1;
}

// LRU Cache count miss (146基础上改编)
// 实现 LRU Cache 再判断啥时候 miss 就好了,返回 miss 数。
int LRUCountMiss(vector<int> &tasks, int size) {
	if (tasks.empty())  return 0; 
	int count = 0;
	unordered_map<int, list<int>::iterator> map;
	list<int> que;
	for (int task : tasks) {
		auto pos = map.find(task);
		if (pos != map.end()) {
			que.erase(pos->second);
			que.push_back(task);
			pos->second = --que.end();
		} else {
			if (map.size() == size) {
				++count;
				map.erase(que.front());
				que.pop_front();
			}
			que.push_back(task);
			map[task] = --que.end();
		}
	}
	return count;
}

// !!Round Robin 求平均等待时间
// 每次运行waiting list中最前面的task，然后在这个task被pop之前到达的tasks先push到waiting list中去
struct Process {
	int arr_t;
	int exe_t;
	Process(int arr_t_, int exe_t_) : arr_t(arr_t_), exe_t(exe_t_) {}
};

float roundRobin(vector<int> &Atime, vector<int> &Etime, int q) {
	if (Atime.empty() || Atime.size() != Etime.size() || q <= 0)  return 0;
	queue<Process> waiting;
	Process running;
	int i = 0; // index of Atime
	int curr_time = 0, wait_time = 0;
	int exe_time;
	while (!waiting.empty() || i < Atime.size()) {
		if (waiting.empty()) {
			waiting.push(Process(Atime[i], Etime[i]));
			curr_time = Atime[i++];
		} else {
			running = waiting.front();
			waiting.pop();
			wait_time += curr_time - running.arr_t;
			exe_time = min(running.exe_t, q);
			curr_time += exe_time;
			running.exe_t -= exe_time;
			running.arr_t = curr_time;
			while (i < Atime.size() && Atime[i] <= curr_time) {
				waiting.push(Process(Atime[i], Etime[i]));
				++i;
			}
			if (running.exe_t > 0)  waiting.push(running);
		}
	}
	return wait_time / float(Atime.size());
}

// Rotate Matrix 有flag标志往左还是往右转90度
// flag == 1: clock-wise  flag == 0: anti-clock-wise
// 注意不是leetcode中的正方形，是矩形！
vector<vector<int> > rotateMatrix(vector<vector<int> > &matrix, int flag) {
	if (matrix.empty() || matrix[0].empty())  return matrix;
	int m = matrix.size(), n = matrix[0].size();
	vector<vector<int> > mat(n, vector<int>(m));
	// transpose
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			mat[i][j] = matrix[j][i];
		}
	}
	// reverse
	if (flag == 1) {
		for (int i = 0; i < n; ++i) {
			reverse(mat[0].begin(), mat[0].end());
		}
	} else {
		reverse(mat.begin(), mat.end());
	}
	return mat;
}

// Insert into cycle linked list
// 插入一个新的节点到一个 sorted cycle linkedlist,返回新的节点。 给的 list 节点不一定是
// 以前后两个node为参考节点，考虑corner case为大于最大小于最小
ListNode* linkedListInsert(ListNode* head, int val) {
	if (!head) {
		head = new ListNode(val);
		head->next = head;
		return head;
	}
	// find the insert position
	ListNode* curr = head;
	do {
		if (curr->val <= val && val <= curr->next->val)  break;
		if (curr->val > curr->next->val &&
			(curr->val <= val || val <= curr->next->val))  break;
		curr = curr->next;
	} while (curr != head);
	// insert new node
	ListNode* node = new ListNode(val);
	node->next = curr->next;
	curr->next = node;
	return node;
}

// Loop in linked list 检查是否有环，以及环的起点在哪里
// 141. Linked List Cycle
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next)  return false;
        ListNode* slow = head;
        ListNode* fast = head;
        do {
            if (!fast->next || !fast->next->next)  return false;
            fast = fast->next->next;
            slow = slow->next;
        } while (slow != fast);
        return true;
    }
};

// 142. Linked List Cycle II
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next)  return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        do {
            if (!fast->next || !fast->next->next)  return NULL;
            fast = fast->next->next;
            slow = slow->next;
        } while (slow != fast);
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

// Shorted job first
class Task {
public:
	int arr, exe;
	Task(int arr_, int exe_) : arr(arr_), exe(exe_) {}
};

class pqCompare {
public:
	bool operator() (Task &lhs, Task &rhs) {
		return lhs.exe > rhs.exe ||
			   (lhs.exe == rhs.exe && lhs.arr > rhs.arr);
	}
};

double sjfWaitingTime(vector<int> &request, vector<int> &durations) {
	if (request.empty() || request.size() != durations.size())  return 0;
	priority_queue<Task, vector<Task>, pqCompare> pq;
	int curr_time = 0, wait_time = 0;
	int i = 0; // index for request and durations
	while (!pq.empty() || i < request.size()) {
		if (pq.empty()) {
			pq.push(Task(request[i], durations[i]));
			curr_time = request[i++];
		} else {
			Task running = pq.top();  pq.pop();
			wait_time += curr_time - running.arr;
			curr_time += running.exe;
			while (i < request.size() && request[i] <= curr_time) {
				pq.push(Task(request[i], durations[i]));
				++i;
			}
		}
	}
	return wait_time / double(request.size());
}

// Binary search tree minimum sum from root to leaf
// method 1: return返回root到leaf的最小sum
int pathSum(TreeNode* root) {
	if (!root)  return 0;
	if (root->left && !root->right) {
		return root->val + pathSum(root->left);
	} else if (!root->left && root->right) {
		return root->val + pathSum(root->right);
	}
	return root->val + min(pathSum(root->left), pathSum(root->right));
}

int pathSum(TreeNode* root) { // method 2
	return minSum(root, 0);
}

int minSum(TreeNode* node, int sum) {
	if (!node)  return sum;
	sum += node->val;
	return min(minSum(node->left, sum), minSum(node->right, sum));
}

// Day change(cell growth)
// int[] dayChange(int[] cells, int days), cells 数组,有 8 个元素,
// 每天的变化情况是当前位置 cell = (cell[i - 1] == cell[i + 1]) ? 0 : 1, 左右相等,
// 当前位置为 0, 不等为 1, 默认 cells[0]左边 和 cells[cells.length - 1]右边的位置元素都是 0, 
// 求 days 天后的变化.
vector<int> dayChange(vector<int> &days, int n) {
	if (days.empty() || n <= 0)  return days;
	int size = days.size();
	days.push_back(0);
	for (int k = 0; k < n; ++k) {
		int left = 0, curr;
		for (int i = 0; i < size; ++i) {
			curr = days[i];
			days[i] = left ^ days[i + 1]; // (left == days[i + 1]) ? 0 : 1;
			left = curr;
		}
	}
	days.pop_back();
	return days;
}

// Maze
// 给个 array,其中只有一格是 9,其他格子是 0 或 1,0 表示此路不通,1 表示可以走,
// 判 断从(0,0) 点开始上下左右移动能否找到这个是 9 的格子
bool maze(vector<vector<int> > &matrix) { // BFS
	if (matrix.empty())  return false;
	if (matrix[0][0] == 9)  return true;
	int di[4] = {0, 0, 1, -1};
	int dj[4] = {1, -1, 0, 0};
	int row = matrix.size(), col = matrix[0].size();
	queue<pair<int, int> > level;
	level.push(make_pair(0, 0));
	while (!level.empty()) {
		int i = level.front().first, j = level.front().second;
		level.pop();
		for (int k = 0; k < 4; ++k) {
			int ii = i + di[k], jj = j + dj[k];
			if (ii >= 0 && ii < row && jj >= 0 && jj < col && 
				matrix[ii][jj] == 1) {
				if (matrix[ii][jj] == 9)  return true;
				matrix[ii][jj] = 0;
				level.push(make_pair(ii, jj));
			} 
		}
	}
	return false;
}

// Minimum Path Sum
int pathSum(TreeNode* root) {
	if (!root)  return 0;
	if (root->left && !root->right) {
		return root->val + pathSum(root->left);
	} else if (!root->left && root->right) {
		return root->val + pathSum(root->right);
	}
	return root->val + min(pathSum(root->left), pathSum(root->right));
}

// Four Integer
// Given four integers, make F(S) = abs(S[0]-S[1])+abs(S[1]-S[2])+abs(S[2]-S[3]) to be largest
// 差最大即排序后相邻的index的diff最大
vector<int> fourInteger(int a, int b, int c, int d) {
	vector<int> nums = {a, b, c, d};
	// 2 0 3 1 -> index diff = 2 3 2
	sort(nums.begin(), nums.end());
	swap(nums[0], nums[2]); // 2 1 0 3
	swap(nums[1], nums[2]); // 2 0 1 3
	swap(nums[2], nums[3]); // 2 0 3 1
	return nums;
}

// Longest Consecutive Arithmetic Sequence
// Given an array, return the number of possible arithmetic sequence
// 413. Arithmetic Slices
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3)  return 0;
        int diff = A[1] - A[0];
        int len = 2;
        int ans = 0;
        for (int i = 2; i < A.size(); ++i) {
            int curr_diff = A[i] - A[i - 1];
            if (curr_diff == diff) {
                ++len;
                ans += len - 2;
            } else {
                len = 2;
                diff = curr_diff;
            }
        }
        return ans;
    }
};

// 446. Arithmetic Slices II - Subsequence (不要求连续)
// dp[i][diff]: 表示以A[i]结尾差为diff的subsequence数量
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() <= 2)  return 0;
        vector<unordered_map<int, int> > dp(A.size());  // array of <diff, count>
        int count = 0;
        for (int i = 1; i < A.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                long d = (long)A[i] - (long)A[j];
                if (d <= INT_MIN || d >= INT_MAX)  continue; // corner case
                int diff = (int)d; // !!要加int
                if (dp[j].find(diff) != dp[j].end()) {
                    dp[i][diff] += dp[j][diff];
                    count += dp[j][diff];
                }
                ++dp[i][diff];  // subsequence of 2: A[j], A[i]
            }
        }
        return count;
    }
};

// Tree Amplitude 即求root到leaf的节点中max-min的最大值
int treeAmplitude(TreeNode* root) {
	if (!root)  return 0;
	return amplitude(root, INT_MAX, INT_MIN);
}

int amplitude(TreeNode* node, int mini, int maxi) {
	if (!node)  return maxi - mini;
	mini = min(mini, node->val);
	maxi = max(maxi, node->val);
	return max(amplitude(node->left, mini, maxi), 
			   amplitude(node->right, mini, maxi));
}

// !!Maximum Minimum Path
// dp[j]保存走到某一行第j列的所有路径中，min最大的那个值
// dp[j]只考虑和左边和上边的情况, 分情况讨论matrix[i][j]与这两个值的大小关系
int maximumMinimumPath(vector<vector<int> > &matrix) { // DP
	if (matrix.empty())  return INT_MIN;
	int row = matrix.size(), col = matrix[0].size();
	int dp[col] = {};  // dp[j]: 某一行第j列的maxmin
	dp[0] = matrix[0][0];
	for (int j = 1; j < col; ++j) { // 第一行因为只有一条路,所以maxmin就是min
		dp[j] = min(dp[j - 1], matrix[0][j]);
	}
	for (int i = 1; i < row; ++i) {
		dp[0] = min(dp[0], matrix[i][0]);
		for (int j = 1; j < col; ++j) {
			if (matrix[i][j] > dp[j] && matrix[i][j] > dp[j - 1]) {
				dp[j] = max(dp[j - 1], dp[j]);
			} else {
				dp[j] = matrix[i][j];
			}
		}
	}
	return dp[matrix.size() - 1];
}

int maximumMinimumPath(vector<vector<int> > &matrix) { // DFS
	if (matrix.empty())  return INT_MIN;
	int row = matrix.size(), col = matrix[0].size();
	int maxmin = INT_MIN;
	dfs(matrix, INT_MIN, 0, 0, maxmin);
	return maxmin;
}

void dfs(vector<vector<int> > &matrix, int pre_min, int i, int j, int &maxmin) {
	if (i == matrix.size() || j == matrix[0].size())  return;
	int cur_min = min(pre_min, matrix[i][j]);
	if (i == matrix.size() - 1 && j == matrix[0].size() - 1) {
		maxmin = max(maxmin, cur_min);
		return;
	}
	dfs(matrix, cur_min, i + 1, j, maxmin);
	dfs(matrix, cur_min, i, j + 1, maxmin);
}

// Sliding Window Minimum (239. Sliding Window Maximum)
// 维护一个单调递增序列
vector<int> minSlidingWindow(vector<int>& nums, int k) {
	if (k <= 0 || nums.size() < k)  return vector<int>();
	vector<int> ans(nums.size() - k + 1);
	list<int> que;
	int j = 0;
	// move the window
	for (int i = 0; i < nums.size(); ++i) {
		while (!que.empty() && nums[que.back()] > nums[i]) {
			que.pop_back();
		}
		que.push_back(i);
		if (i < k - 1)  continue;
		ans[j++] = nums[que.front()];
		if (que.front() == i - k + 1)  que.pop_front();
	}
	return ans;
}

// 74. Search a 2D Matrix
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty())  return false;
        int row = matrix.size(), col = matrix[0].size();
        int left = 0, right = row * col - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int i = mid / col, j = mid % col;
            if (target == matrix[i][j]) {
                return true;
            } else if (target < matrix[i][j]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return false;
    }
};

// 240. Search a 2D Matrix II
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty())  return false;
        int row = matrix.size(), col = matrix[0].size();
        int i = row - 1, j = 0;
        while (i >= 0 && j < col) {
            if (matrix[i][j] == target)  return true;
            (target < matrix[i][j]) ? --i : ++j;
        }
        return false;
    }
};

// Close Two Sum
// 找两数和最接近target
vector<double> closeTwoSum(double capacity, vector<double> &weights) {
	if (weights.size() <= 1)  return vector<double>();
	sort(weights.begin(), weights.end());
	int best1, best2;
	double min_diff = INT_MAX;
	int left = 0, right = weights.size() - 1;
	while (left < right) {
		int diff = capacity - weights[left] - weights[right];
		if (diff >= 0 && diff < min_diff) {
			min_diff = diff;
			best1 = left;  best2 = right;
		}
		(diff >= 0) ? ++left : --right;
	}
	if (min_diff == INT_MAX)  return vector<double>();
	return vector<double>{weights[best1], weights[best2]};
}