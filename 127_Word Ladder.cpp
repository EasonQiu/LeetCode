#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution { // version 2, two way bfs, beats 84.60%
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (wordList.size() <= 1)  return 0;
        // init the hashset
        unordered_set<string> unexplored(wordList.size());
        for (string str : wordList)  unexplored.insert(str);
        // check corner cases
        if (unexplored.find(endWord) == unexplored.end())  return 0;
        // init two queues for two way BFS
        unordered_set<string> queue1, queue2, *set1, *set2;
        queue1.insert(beginWord);  unexplored.erase(beginWord);
    	queue2.insert(endWord);    unexplored.erase(endWord);
        // two way BFS
        int length = 2;
        while (!queue1.empty() && !queue2.empty()) {
        	// choose the smaller one to BFS
        	if (queue1.size() <= queue2.size()) {
        		set1 = &queue1;  set2 = &queue2;
        	} else {
        		set1 = &queue2;  set2 = &queue1;
        	}
        	// create the next level of words
        	unordered_set<string> temp(set1->size());
        	for (string word : *set1) {
        		for (int m = 0; m < word.size(); ++m) {
        			char oriCh = word[m];
        			for (char ch = 'a'; ch <= 'z'; ++ch) {
        				if (ch == oriCh)  continue;
        				word[m] = ch;
        				if (set2->find(word) != set2->end()) {
        					return length;
        				} else if (unexplored.find(word) != unexplored.end()) {
        					unexplored.erase(word);
        					temp.insert(word);
        				}
        				word[m] = oriCh;
        			}
        		}
        	}
        	swap(*set1, temp);  ++length;
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