// Given a 2D board and a list of words from the dictionary, find all words in the board.

// Each word must be constructed from letters of sequentially adjacent cell, where "adjacent"
// cells are those horizontally or vertically neighboring. The same letter cell may not be 
// used more than once in a word.

// For example,
// Given words = ["oath","pea","eat","rain"] and board =
// [
//   ['o','a','a','n'],
//   ['e','t','a','e'],
//   ['i','h','k','r'],
//   ['i','f','l','v']
// ]
// Return ["eat","oath"].

// 感想：记住c++二维数组初始化方法，以及board[0] = vector<char>{'e', 't', 'a', 'e'};
//      TrieNode中标记该节点是否为一个单词可以有多种形式，不一定要bool可以是其他int或者string
//      构建trie tree有两种方法，一种为需要查找的目标words建树，一种为存储words的dict建树，选两者中容易的

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TrieNode {
 public:
  TrieNode* childs[26];
  string word;
  TrieNode() : word("") {
    for (int i = 0; i < 26; ++i)  childs[i] = NULL;
  }
};

class Solution {
 public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    if (board.empty() || words.empty())  return vector<string>();
    // init the Trie tree
    root = new TrieNode();
    for (string& word : words)  addWord2Trie(word);
    // search words in matrix
    vector<string> ans;
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[0].size(); ++j) {
        searchWord(board, root, i, j, ans);
      }
    }
    return ans;
  }

  void searchWord(vector<vector<char> > &board, TrieNode *node, 
                  int i, int j, vector<string> &ans) {
    // base case
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())  return;
    if (board[i][j] == '/' || !node->childs[board[i][j] - 'a'])  return;
    node = node->childs[board[i][j] - 'a'];
    // find one word, avoid duplicates
    if (node->word != "") {
      ans.push_back(node->word);  node->word = "";
    }
    // go to the next letter
    char cache = board[i][j];
    board[i][j] = '/';
    searchWord(board, node, i + 1, j, ans);
    searchWord(board, node, i - 1, j, ans);
    searchWord(board, node, i, j + 1, ans);
    searchWord(board, node, i, j - 1, ans);
    board[i][j] = cache;
  }

  void addWord2Trie(string &word) {
    int index;
    TrieNode *curr = root;
    for (int i = 0; i < word.size(); ++i) {
      index = word[i] - 'a';
      if (!curr->childs[index])  curr->childs[index] = new TrieNode();
      curr = curr->childs[index];
    }
    curr->word = word;
  }

 private:
  TrieNode* root;
};

int main() {
	vector<vector<char> > board = {{'o', 'a', 'a', 'n'},
																 {'e', 't', 'a', 'e'},
																 {'i', 'h', 'k', 'r'},
																 {'i', 'f', 'l', 'v'}};
	vector<string> words = {"oath","pea","eat","rain"};

	Solution sol;
	vector<string> ans = sol.findWords(board, words);
	for (string& word : ans)  cout << word << " ";
	cout << endl;

	return 0;
}