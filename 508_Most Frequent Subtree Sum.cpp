// Given the root of a tree, you are asked to find the most frequent subtree sum. 
// The subtree sum of a node is defined as the sum of all the node values formed by the 
// subtree rooted at that node (including the node itself). So what is the most frequent 
// subtree sum value? If there is a tie, return all the values with the highest frequency 
// in any order.

// Examples 1
// Input:

//   5
//  /  \
// 2   -3
// return [2, -3, 4], since all the values happen only once, return all of them in any order.
// Examples 2
// Input:

//   5
//  /  \
// 2   -5
// return [2], since 2 happens twice, however -5 only occur once.
// Note: You may assume the sum of values in any subtree is in the range of 32-bit signed integer.


class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if (!root)  return vector<int>();
        unordered_map<int, int> dict; // <sum, freq>
        traverse(root, dict);
        unordered_map<int, vector<int> > freq; // <freq, array of sums>
        int max_freq = INT_MIN;
        for (auto &pair : dict) {
            freq[pair.second].push_back(pair.first);
            max_freq = max(max_freq, pair.second);
        }
        return freq[max_freq];
    }
    
    int traverse(TreeNode* node, unordered_map<int, int> &dict) {
        if (!node)  return 0;
        int sum = node->val + traverse(node->left, dict) + traverse(node->right, dict);
        ++dict[sum];
        return sum;
    }
};

class Solution {
public:
  vector<int> findFrequentTreeSum(TreeNode* root) {
  	vector<int> ans;
  	if (!root)  return ans;
    unordered_map<int, int> counter; // <sum, frequency>
    int max_frequency = 0;
    helper(root, counter, max_frequency, ans);
    return ans;
  }

  int helper(TreeNode *root, unordered_map<int, int> &counter, int &max_frequency, 
  					 vector<int> &ans) {
  	if (!root)  return 0;
  	int sum = root->val + helper(root->left, counter, max_frequency, ans) + 
  						helper(root->right, counter, max_frequency, ans);
  	if (++counter[sum] > max_frequency) {
  		ans.clear();  ans.push_back(sum);
  		max_frequency = counter[sum];
  	} else if (counter[sum] == max_frequency) {
  		ans.push_back(sum);
  	}
  	return sum;
  }
};