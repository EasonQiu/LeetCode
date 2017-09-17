// Given a list of unique words, find all pairs of distinct indices (i, j) in the given list, so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.

// Example 1:
// Given words = ["bat", "tab", "cat"]
// Return [[0, 1], [1, 0]]
// The palindromes are ["battab", "tabbat"]
// Example 2:
// Given words = ["abcd", "dcba", "lls", "s", "sssll"]
// Return [[0, 1], [1, 0], [3, 2], [2, 4]]
// The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]

// 感想：根节点对应于空字符串，有点像dummy node的感觉。要查找string中index=0个字符，要去trie中level 0中寻找；
// 而它所对应的节点在level 1中，相当于前驱节点才能获得对应的真实节点。

#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

class TrieNode {
public:
    TrieNode *child_nodes[26];
    int index; // -1 means it's not a leaf
    list<int> palin_indices;
    
    TrieNode(int index_ = -1) : index(index_) {
        for (int i = 0; i < 26; ++i)  child_nodes[i] = NULL;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    void addWord(string word, int index) {
        TrieNode *crawl = root;
        int pos;
        for (int i = (int)word.size() - 1; i >= 0; --i) {
            pos = word[i] - 'a';
            if (!crawl->child_nodes[pos])  crawl->child_nodes[pos] = new TrieNode();
            if (isPalindrome(word, 0, i))  crawl->palin_indices.push_back(index);
            crawl = crawl->child_nodes[pos];
        }
        crawl->index = index;
        crawl->palin_indices.push_back(index);
    }
    
    void searchWord(const string &word, int index, vector<vector<int> > &ans) {
        vector<int> pair(2, 0);  pair[0] = index;
        // find all the words(right part) that ends with word(left part)
        // match part of string word (0 to size - 2)
        // eg: "tab" + "" or "at"
        TrieNode *crawl = root;
        for (int i = 0; i < word.size(); ++i) {
            TrieNode *child = crawl->child_nodes[word[i] - 'a'];
            // when right part is shorter than left part
            if (crawl->index >= 0 && crawl->index != index &&
            		// match the letters before word[i]
                isPalindrome(word, i, word.size() - 1)) {
                pair[1] = crawl->index;  ans.push_back(pair);
            }
            if (!child)  return;
            crawl = child;
        }
        // match the whole string word
        // when right part is longer than left part
        // eg: "tab" + "eebat" or "bat"
        for (int i : crawl->palin_indices) {
            if (i != index) {
                pair[1] = i;  ans.push_back(pair);
            }
        }
    }

private:
    TrieNode *root;
    
    bool isPalindrome(const string &word, int left, int right) {
        if (left > right)  return false;
        while (left < right) {
            if (word[left++] != word[right--])  return false;
        }
        return true;
    }
};

class Solution {
public:
    vector<vector<int> > palindromePairs(vector<string>& words) {
        vector<vector<int> > ans;
        if (words.size() == 0)  return ans;
        Trie dict;
        for (int i = 0; i < words.size(); ++i)  dict.addWord(words[i], i);
        for (int i = 0; i < words.size(); ++i)  dict.searchWord(words[i], i, ans);
        // final result
        return ans;
    }
};

int main() {
    vector<string> words = {"a", ""};
    Solution sol;
    
    vector<vector<int> > ans = sol.palindromePairs(words);
    for (auto& pair : ans) {
        cout << pair[0] << " " << pair[1] << endl;
    }
    
    return 0;
}