// Design a data structure that supports the following two operations:

// void addWord(word)
// bool search(word)
// search(word) can search a literal word or a regular expression string 
// containing only letters a-z or .. A . means it can represent any one letter.
// search(".ad") -> true
// search("b..") -> true

#include <iostream>
#include <string>

using namespace std;

#define ALPHABET_SIZE 26

class TrieNode {
public:
  TrieNode* child_nodes[ALPHABET_SIZE];
  char val;
  bool is_leaf;
  int count;
  // Initialize your data structure here.
  TrieNode() : val('/'), is_leaf(false), count(0) {
    for (int i = 0; i < ALPHABET_SIZE; ++i)  child_nodes[i] = NULL;
  }
  TrieNode(char val_) : val(val_), is_leaf(false), count(0) {
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
    crawl->is_leaf = true;  ++crawl->count;
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

int main() {
  WordDictionary dict;
  dict.addWord("abc");
  cout << dict.search("a.") << dict.search(".bd") << dict.search("...") << endl;
  dict.addWord("abcdef");
  cout << dict.search("....") << dict.search("ab.de") << dict.startsWith("a.cdf") << endl;

  return 0;
}