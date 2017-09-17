// Given a list of words (without duplicates), please write a program that
// returns all concatenated words in the given list of words.
// A concatenated word is defined as a string that is comprised entirely of
// at least two shorter words in the given array.

// Example:
// Input: ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses",
// "rat","ratcatdogcat"]
// Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]

// Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats";
//  "dogcatsdog" can be concatenated by "dog", "cats" and "dog";
// "ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".

// 感想：string出现时要考虑是否是空串

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TrieNode {
 public:
 	TrieNode* child_nodes[26];
 	bool is_leaf;
 	TrieNode() : is_leaf(false) {
 		for (int i = 0; i < 26; ++i)  child_nodes[i] = NULL;
 	}
};

class Trie {
 public:
 	Trie() {
 		root = new TrieNode();
 	}

 	// insert words
 	void addWord(string word) {
 	  if (word == "")  return;
 		int index;
 		TrieNode *crawl = root;
 		for (int level = 0; level < word.size(); ++level) {
 			index = word[level] - 'a';
 			if (!crawl->child_nodes[index]) {
 				crawl->child_nodes[index] = new TrieNode();
 			}
 			crawl = crawl->child_nodes[index];
 		}
 		crawl->is_leaf = true;
 	}
 	
 	// search words
 	bool isConcatenatedWord(string word) {
 	  if (word == "")  return false;
 		return searchHelper(word, root, 0, 0);
 	}

	bool searchHelper(const string &word, TrieNode *node, int level, int words_num) {
		TrieNode *crawl = node;
 		for (int i = level; i < word.size(); ++i) {
 			TrieNode *child = crawl->child_nodes[word[i] - 'a'];
 			if (!child)  return false;
 			if (child->is_leaf) {
 				// base case
 				if (i == word.size() - 1)  return words_num > 0;
 				// split the word
 				if (searchHelper(word, root, i + 1, words_num + 1))  return true;
 			}
 			crawl = child;
 		}
 		return false;
 	}

 	// recursion char by char
 	bool searchHelper2(const string &word, TrieNode *crawl, int level, int words_num) {
 	  // base case 1
 	  if (level == word.size())  return false;
 		// regular case
 		TrieNode *child = crawl->child_nodes[word[level] - 'a'];
 		if (!child)  return false;
 		if (child->is_leaf) {
			// base case 2
			if (level == word.size() - 1)  return words_num > 0;
			// split the word
			if (searchHelper(word, root, level + 1, words_num + 1))  return true;
		};
 		return searchHelper(word, child, level + 1, words_num);
 	}

 private:
 	TrieNode *root;
};

class Solution {
public:
	vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
		// base cases
		vector<string> ans;
		if (words.size() <= 2)  return ans;
		// build the trie tree for words
		Trie dict;
		for (string& word : words) {
			dict.addWord(word);
		}
		// check concatenated words
		for (string& word : words) {
			if (dict.isConcatenatedWord(word))  ans.push_back(word);
		}
		// final result
		return ans;
	}
};

int main() {
	vector<string> words = {"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"};
	Solution sol;

  vector<string> ans = sol.findAllConcatenatedWordsInADict(words);
  for (string& word : ans) {
  	cout << word << " ";
  }
  cout << endl;
}