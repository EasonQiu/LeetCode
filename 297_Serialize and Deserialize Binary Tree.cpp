// Serialization is the process of converting a data structure or object into a sequence of 
// bits so that it can be stored in a file or memory buffer, or transmitted across a network 
// connection link to be reconstructed later in the same or another computer environment.

// Design an algorithm to serialize and deserialize a binary tree. There is no restriction on 
// how your serialization/deserialization algorithm should work. You just need to ensure that 
// a binary tree can be serialized to a string and this string can be deserialized to the 
// original tree structure.

// For example, you may serialize the following tree

//     1
//    / \
//   2   3
//      / \
//     4   5
// as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree. 
// You do not necessarily need to follow this format, so please be creative and come up with 
// different approaches yourself.
// Note: Do not use class member/global/static variables to store states. Your serialize and 
// deserialize algorithms should be stateless.


// 解法用先序遍历，用#标记节点已经到头
// 如上图的序列化结果是："1 2 # # 3 4 # # 5 # #"
class Codec {
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
  	stringstream stream;
  	serialize_help(root, stream);
  	return stream.str();
  }

  void serialize_help(TreeNode *root, stringstream &stream) {
  	if (root) {
  		stream << root->val << " ";
  		serialize_help(root->left, stream);
  		serialize_help(root->right, stream);
  	} else {
  		stream << "# ";
  	}
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
  	stringstream stream(data);
  	return deserialize_help(stream);
  }

  TreeNode* deserialize_help(stringstream &stream) {
  	string str;  stream >> str;
  	if (str == "#")  return NULL;
  	int val = stoi(str);
  	TreeNode *node = new TreeNode(val);
  	node->left = deserialize_help(stream);
  	node->right = deserialize_help(stream);
  	return node;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));