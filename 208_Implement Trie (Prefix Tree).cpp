/**
 * Your Trie object will be instantiated and called as such:
 * Trie trie;
 * trie.insert("lintcode");
 * trie.search("lint"); will return false
 * trie.startsWith("lint"); will return true
 */

// 指针数组是需要初始化成NULL的

#include <iostream>
#include <string>

using namespace std;

#define ALPHABET_SIZE 26

class TrieNode {
 public:
  TrieNode* childs[26];
  bool is_word;
  TrieNode() : is_word(false) {
    for (int i = 0; i < 26; ++i)  childs[i] = NULL;
  }
};

class Trie {
 public:
  /** Initialize your data structure here. */
  Trie() {
    root = new TrieNode();
  }
    
  /** Inserts a word into the trie. */
  void insert(string word) {
    int index;
    TrieNode *node = root;
    for (int i = 0; i < word.size(); ++i) {
      index = word[i] - 'a';
      if (!node->childs[index])  node->childs[index] = new TrieNode();
      node = node->childs[index];
    }
    node->is_word = true;
  }
    
  /** Returns if the word is in the trie. */
  bool search(string word) {
    int index;
    TrieNode *node = root;
    for (int i = 0; i < word.size(); ++i) {
      index = word[i] - 'a';
      if (!node->childs[index])  return false;
      node = node->childs[index];
    }
    return node->is_word;
  }
    
  /** Returns if there is any word in the trie that starts with the given prefix. */
  bool startsWith(string prefix) {
    int index;
    TrieNode *node = root;
    for (int i = 0; i < prefix.size(); ++i) {
      index = prefix[i] - 'a';
      if (!node->childs[index])  return false;
      node = node->childs[index];
    }
    if (node->is_word)  return true;
    for (int i = 0; i < 26; ++i) {
      if (node->childs[i])  return true;
    }
    return false;
  }

 private:
  TrieNode *root;
};

int main() {
  Trie trie;
  trie.insert("abc");
  cout << trie.search("abc") << trie.search("ab") << trie.startsWith("ab") << endl;
  trie.insert("abcdef");
  cout << trie.search("abcdef") << trie.search("de") << trie.startsWith("abcd") << endl;

  return 0;
}