// 102_Binary Tree Level Order Traversal
class Solution {
public:
    // recursion version, DFS
    int maxDepth(TreeNode* root) {
        if (!root)  return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
    void dfs(vector<vector<int> >& result, TreeNode* p, int level) {
        if (p){
            result[level].push_back(p->val);
            dfs(result, p->left,  level + 1);
            dfs(result, p->right, level + 1);
        }
    }
    vector<vector<int> > levelOrder(TreeNode* root) {
        int depth = maxDepth(root);
        vector<vector<int> > result(depth);
        dfs(result, root, 0);
        return result;
    }
    // non-recursion version, BFS
    vector<vector<int>> levelOrder(TreeNode* root){ 
        vector<vector<int> > result;
        queue<TreeNode*> levelNodes;
        vector<int> levelValues;
        TreeNode* node;
        // traverse nodes level by level
        if (!root) return result;
        levelNodes.push(root);
        while (!levelNodes.empty()){ 
            levelValues.clear();
            int size = levelNodes.size();
            for (int i = 0; i < size; ++i){
                node = levelNodes.front();  levelNodes.pop();
                levelValues.push_back(node->val);
                if (node->left)  levelNodes.push(node->left);
                if (node->right) levelNodes.push(node->right);
            }
            result.push_back(levelValues);
        }
        return result;
    }
};

// 94_Binary Tree Inorder & Preorder Traversal
class Solution {
public:
	// non-recursion version, DFS, Preorder
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        vector<TreeNode*> stack;
        TreeNode* node = root;
    	while (node || !stack.empty()){
        	if (node) { // need to push nodes and go down left
            	result.push_back(node->val);
            	stack.push_back(node);
            	node = node->left;
        	}else { // need to pop nodes and go down right
            	node = stack.back();  stack.pop_back();
            	node = node->right;
        	}
    	}
        return result;
    }
    // non-recursion version, DFS, Inorder
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        vector<TreeNode*> stack;
        TreeNode* node = root;
    	while (node || !stack.empty()){
        	if (node) { // need to push nodes and go down left
            	stack.push_back(node);
            	node = node->left;
        	}else { // need to pop nodes and go down right
            	node = stack.back();  stack.pop_back();
            	result.push_back(node->val);
            	node = node->right;
        	}
    	}
        return result;
    }
    // non-recursion version, DFS, Postorder
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;
    stack<TreeNode*> stack; // store nodes waiting to output
    TreeNode *node = root, *last_node = NULL; // node points to unprocessed node
    while (node || !stack.empty()) {
        if (node) {
            stack.push(node);
            node = node->left;
        } else {
            TreeNode *top_node = stack.top();
            if (top_node->right && top_node->right != last_node) {
                node = top_node->right;
            } else {
                ans.push_back(top_node->val);
                last_node = top_node;
                stack.pop();
            }
        }
    }
    return ans;
  }
    // non-recursion version, DFS, Postorder
  vector<int> postorderTraversal(TreeNode* root) {
    deque<int> ans;
    stack<TreeNode*> stack;
    TreeNode *node = root;
    while (node || !stack.empty()) {
        if (node) {
            stack.push(node);
            ans.push_front(node->val);
            node = node->right;
        } else {
            node = stack.top();  stack.pop();
            node = node->left;
        }
    }
    return vector<int>(ans.begin(), ans.end());
  }
};

// 144_Binary Tree Preorder Traversal
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode* node;
        vector<TreeNode*> stack;
        vector<int> result;
        // First in Last out
        if (!root) return result;
        stack.push_back(root);
        while (!stack.empty()){ 
            node = stack.back();  stack.pop_back();
            result.push_back(node->val);
            if (node->right) stack.push_back(node->right);
            if (node->left)  stack.push_back(node->left);
        }
        return result;
    }
};

// 98_Validate Binary Search Tree
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return validate(root, prev);
    }
    bool validate(TreeNode* node, TreeNode* &prev) {
        if (node == NULL) return true;
        // check if the left subtree is validated
        if (!validate(node->left, prev)) return false;
        // check if the current node is validated
        if (prev != NULL && prev->val >= node->val) return false;
        // in-order update prev
        prev = node;
        // check if the left subtree is validated
        return validate(node->right, prev);
    }
};

// 110_Balanced Binary Tree
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        if (abs(depth(root->left) - depth(root->right)) > 1) return false;
        if (!isBalanced(root->left)) return false;
        return isBalanced(root->right);
    }
    int depth(TreeNode* root){
        if (!root)  return 0;
        return max(depth(root->left), depth(root->right)) + 1;
    }
};

// 450_Delete Node in a BST
class Solution {
public:
	pair<TreeNode*, TreeNode*> findNode(TreeNode* p, TreeNode* parent, int key) {
        if (!p) return make_pair(p, parent);
        if (key < p->val)
            return findNode(p->left, p, key);
        else if (key > p->val)
            return findNode(p->right, p, key);
        else
            return make_pair(p, parent);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        pair<TreeNode*, TreeNode*> pos = findNode(root, NULL, key); // pair<current, parent>
        if (!pos.first) return root; // do not find the key in the tree
        if (!pos.first->left){ // do not have a left child
            if (!pos.second){ // parent is NULL
                root = root->right;
                delete pos.first;  pos.first = NULL;
                return root;
            }else { // parent is not NULL
                if (pos.first == pos.second->right){ // current is right child of parent
                    pos.second->right = pos.first->right;
                    delete pos.first;  pos.first = NULL;
                    return root;
                }else{ // current is left child of parent
                    pos.second->left = pos.first->right;
                    delete pos.first;  pos.first = NULL;
                    return root;
                }
            }
        }else{ // have a left child
            pair<TreeNode*, TreeNode*> lChild = make_pair(pos.first->left, pos.first); // pair<child, parent>
            while (lChild.first->right){  // find largest node in left subtree
                lChild.second = lChild.first;
                lChild.first = lChild.first->right;
            }
            if (lChild.second == pos.first){ // lChild is exactly the left child of current
                pos.first->val = lChild.first->val;
                pos.first->left = lChild.first->left;
                delete lChild.first;  lChild.first = NULL;
                return root;
            }else { // lChild is not the left child of current
                pos.first->val = lChild.first->val;
                lChild.second->right = lChild.first->left;
                delete lChild.first;  lChild.first = NULL;
                return root;
            }
        }
    }
};

// 99_Recover Binary Search Tree
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *pos1 = NULL, *pos2 = NULL, *prev = NULL, *pos1Prev = NULL;
        int tmp;
        
        search(root, prev, pos1, pos1Prev, pos2);
        if (pos2){ // two nodes are not next to each other
            tmp = pos1Prev->val;  pos1Prev->val = pos2->val;  pos2->val = tmp;
        }else{ // two nodes are next to each other
            tmp = pos1->val;  pos1->val = pos1Prev->val;  pos1Prev->val = tmp;
        }
    }
    
    void search(TreeNode* p, TreeNode* &prev, TreeNode* &pos1, TreeNode* &pos1Prev, TreeNode* &pos2){
        if (p){
            // search left subtree
            search(p->left, prev, pos1, pos1Prev, pos2);
            // check the current node
            if (prev != NULL && prev->val >= p->val){
                if (!pos1){
                    pos1 = p;  pos1Prev = prev;
                }else if (!pos2){
                    pos2 = p;  return;
                }
            }
            prev = p;
            // search right subtree
            search(p->right, prev, pos1, pos1Prev, pos2);
        }
    }
};


// 236_Lowest Common Ancestor of a Binary Tree
class Solution {
public:
    // version 1
    // If the current (sub)tree contains both p and q, then the function result is their LCA. 
    // If only one of them is in that subtree, then the result is that one of them. 
    // If neither are in that subtree, the result is null/None/nil.
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || root == p || root == q) return root;
        TreeNode* left =  lowestCommonAncestor(root->left,  p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left == NULL)  return right;
        else if (right == NULL)  return left;
        return root;
    }

    // version 2
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1, path2, currPath;
        TreeNode* LCA = NULL;
        findPath(root, p, q, currPath, path1, path2);
    
        unsigned long size = min(path1.size(), path2.size());
        for (int i = 0; i < size; ++i){
            if (path1[i] == path2[i])  LCA = path1[i];
            else break;
        }
        return LCA;
    }
    
    void findPath(TreeNode* root, TreeNode* &p, TreeNode* &q, vector<TreeNode*> &currPath,
                  vector<TreeNode*> &path1, vector<TreeNode*> &path2){
        if (root){
            currPath.push_back(root);
            if (root == p){
                if (path1.empty())  path1 = currPath;
                else if (path2.empty()){
                    path2 = currPath;  return;
                }
            }else if (root == q){
                if (path1.empty())  path1 = currPath;
                else if (path2.empty()){
                    path2 = currPath;  return;;
                }
            }
            
            findPath(root->left, p, q, currPath, path1, path2);
            findPath(root->right, p, q, currPath, path1, path2);
            currPath.pop_back();
        }
    }
};

// 235_Lowest Common Ancestor of a Binary Search Tree
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root){
            if ((root->val - p->val) * (root->val - q->val) <= 0)
                return root;
            else if (root->val > p->val && root->val > q->val)
                root = root->left;
            else if (root->val < p->val && root->val < q->val)
                root = root->right;
        }
        return root;
    }
};

// 437_Path Sum III
class Solution {
public:
    int pathSum(TreeNode *root, int sum) {
        if (!root) return 0;
        vector<int> sums;
        int num = 0;
        dfs(root, sums, sum, num);
        return num;
    }
    
    void dfs(TreeNode *p, vector<int> &sums, const int &sum, int &num) {
        sums.push_back(0);
        for (int i = 0; i < sums.size(); ++i) {
            sums[i] += p->val;
            if (sums[i] == sum) ++num;
        }
        if (p->left)  dfs(p->left, sums, sum, num);
        if (p->right) dfs(p->right, sums, sum, num);
        
        sums.pop_back();
        for (int i = 0; i < sums.size(); ++i) {
            sums[i] -= p->val;
        }
    }
};
class Solution { // "one dimensional array range sum" problem
public:
    int help(TreeNode* root, int sum, unordered_map<int, int>& store, int pre) {
        if (!root) return 0;
        root->val += pre;
        int res = (root->val == sum) + (store.count(root->val - sum) ? store[root->val - sum] : 0);
        store[root->val]++;
        res += help(root->left, sum, store, root->val) + help(root->right, sum, store, root->val);
        store[root->val]--;
        return res;
    }

    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> store;
        return help(root, sum, store, 0);
    }
};

// 100_same tree
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p != nullptr  && q != nullptr)
            return ( p->val==q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right) );
        else if (p == nullptr  && q == nullptr)
            return true;
        else
            return false;
    }
};

// 230_Kth Smallest Element in a BST
class Solution { // dfs, non-recursion
public:
    /*Any tree traversal could be divided into two parts: traverse down and traverse up.
    Here, for any node, we push it to stack, and go to its left child. This is traverse down.
    When the node is null, we begin to traverse up by getting the top node from the root.
    */
    int kthSmallest(TreeNode* root, int k) {
        if(!root || k <= 0) return INT_MIN;
        stack<TreeNode*> my_stack;
        while(root || !my_stack.empty()){
            if(root){
                my_stack.push(root);
                root = root->left;
            } else {
                root = my_stack.top();  my_stack.pop();
                if(--k == 0) return root->val;
                root = root->right;
            }
        }
        return INT_MIN;
    }
};

// 108_Convert Sorted Array to Binary Search Tree
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty())  return NULL;
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

// 105. Construct Binary Tree from Preorder and Inorder Traversal
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return NULL;
        return build(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
    TreeNode* build(const vector<int>& preorder, const vector<int>& inorder,
                    int leftPre, int rightPre, int leftIn, int rightIn){
        if (leftPre == rightPre){
            return  new TreeNode(preorder[leftPre]);
        }else {
            TreeNode* node = new TreeNode(preorder[leftPre]);
            int pos = leftIn;
            while (inorder[pos] != preorder[leftPre])  ++pos;
            if (leftIn < pos)
                node->left = build(preorder, inorder, leftPre+1, leftPre+pos-leftIn, leftIn, pos-1);
            if (pos < rightIn)
                node->right = build(preorder, inorder, leftPre+pos-leftIn+1, rightPre, pos+1, rightIn);
            return node;
        }
    }
};

// 337. House Robber III
class Solution {
public:
    int rob(TreeNode* root) {
        return rob_help(root).first;
    }
    // I maintain result in a pair, first part indicates best benefit no matter whether includes himself, 
    // and second part indicates the one without including himself.
    // So root->val + left.second + right.second means includes himself but skip all his children.
    pair<int, int> rob_help(TreeNode *root) {
        pair<int, int> result(0, 0);
        if (root != NULL) {
            pair<int, int> left = rob_help(root->left);
            pair<int, int> right = rob_help(root->right);
            result.second = left.first + right.first;
            result.first = max(root->val + left.second + right.second, result.second);
        }
        return result;
    }
};

// 222. Count Complete Tree Nodes
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        // calculate the max height of tree
        int maxHeight = 1;
        TreeNode* tmp = root;
        while (tmp->left) {
            tmp = tmp->left;  ++maxHeight;
        }
        return count(root, 1, maxHeight);
    }
    int count(TreeNode* node, int height, const int &maxHeight){
        if (!node) return 0;
        // calculate the height of left subtree
        int h = height;
        if (TreeNode* tmp = node->left) {
            ++h;
            while (tmp && tmp->right) {
                tmp = tmp->right;  ++h;
            }
        }
        // calculate the number of nodes
        if (h == maxHeight){ // a perfect left subtree
            return (int)pow(2,maxHeight - height) - 1 + count(node->right, height+1, maxHeight) + 1;
        }else { // not a perfect left subtree
            return count(node->left, height+1, maxHeight) + (int)pow(2,maxHeight - height - 1) - 1 + 1;
        }
        
    }
};