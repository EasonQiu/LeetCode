#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

// Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

// Only one letter can be changed at a time.
// Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
// For example,

// Given:
// beginWord = "hit"
// endWord = "cog"
// wordList = ["hot","dot","dog","lot","log","cog"]
// As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
// return its length 5.

// Note:
// Return 0 if there is no such transformation sequence.
// All words have the same length.
// All words contain only lowercase alphabetic characters.
// You may assume no duplicates in the word list.
// You may assume beginWord and endWord are non-empty and are not the same.

class Solution {  // version 2, two way BFS, 98%
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end())  return 0;  // corner case
        unordered_set<string> set1 = {beginWord};
        unordered_set<string> set2 = {endWord};
        int len = 1;
        while (!set1.empty() && !set2.empty()) {
            ++len;
            if (set1.size() > set2.size())  swap(set1, set2);
            unordered_set<string> next_set;
            for (string curr : set1) {
                for (int i = 0; i < curr.size(); ++i) {
                    char ori_ch = curr[i];
                    for (char ch = 'a';  ch <= 'z'; ++ch) {
                        if (ch == ori_ch)  continue;
                        curr[i] = ch;
                        if (set2.count(curr))  return len;
                        if (!dict.count(curr))  continue;
                        next_set.insert(curr);
                        dict.erase(curr);
                    }
                    curr[i] = ori_ch;
                }
            }
            swap(set1, next_set);
        }
        return 0;
    }
};

class Solution1 { // version 1
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (wordList.size() <= 1)  return 0;
        int length = 0;
        // init the hashset and queue
        unordered_set<string> original(wordList.size());
        for (string str : wordList)  original.insert(str);
        unordered_set<string> explored(wordList.size());
        queue<string> queues;  
        explored.insert(beginWord);  queues.push(beginWord);
        // simple BFS
        while (!queues.empty()) {
        	++length;
        	int size = queues.size();
        	for (int i = 0; i < size; ++i) {
        		// pop the words in the current level
        		string word = queues.front();  queues.pop();
        		if (word == endWord)  return length;
        		// add words of the next level
        		for (int m = 0; m < word.size(); ++m) {
        			char oriCh = word[m];
        			for (char ch = 'a'; ch <= 'z'; ++ch) {
        				if (ch == oriCh)  continue;
        				word[m] = ch;
        				if (original.find(word) != original.end()
        					&& explored.find(word) == explored.end()) {
        					queues.push(word);
        					explored.insert(word);
        				}
        			}
        			word[m] = oriCh;
        		}
        	}
        }
        return 0;
    }
};

class Solution0 { // version 0
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (wordList.size() <= 1)  return 0;
        int length = 0;
        // init the hashset and queue
        unordered_set<string> explored(wordList.size());
        queue<string> queues;  
        explored.insert(beginWord);  queues.push(beginWord);
        // simple BFS
        while (!queues.empty()) {
        	++length;
        	int size = queues.size();
        	for (int i = 0; i < size; ++i) {
        		// pop the words in the current level
        		string word = queues.front();  queues.pop();
        		if (word == endWord)  return length;
        		// add words of the next level
        		for (int j = 0; j < wordList.size(); ++j) {
        			if (explored.find(wordList[j]) == explored.end()
        				&& onlyChangeOneWord(word, wordList[j])) {
        				queues.push(wordList[j]);
        				explored.insert(wordList[j]);
        			}
        		}
        	}
        }
        return 0;
    }

    bool onlyChangeOneWord(string word1, string word2) {
    	int diff = 0;
    	for (int i = 0; i < word1.size(); ++i) {
    		if (word1[i] != word2[i])  ++diff;
    	}
    	return diff == 1 ? 1 : 0;
    }
};

int main() {
	string beginWord = "hit", endWord = "cog";
	vector<string> wordList;
	wordList.push_back("hot");  wordList.push_back("dot");
	wordList.push_back("dog");  wordList.push_back("lot");
	wordList.push_back("log");  wordList.push_back("cog");

	Solution s;
	cout << s.ladderLength(beginWord, endWord, wordList) << endl;
	return 0;
}