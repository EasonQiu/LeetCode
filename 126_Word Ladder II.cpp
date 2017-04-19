#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution { // version 2, two way BFS + DFS
public:
    vector<vector<string> > findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string> > answer;
        if (wordList.size() <= 1)  return answer;
        // init the hashset
        unordered_set<string> unexplored(wordList.size());
        for (string str : wordList)  unexplored.insert(str);
        // check corner cases
        if (unexplored.find(endWord) == unexplored.end())  return answer;
        // two way BFS to find the length of ladders
        int length = getLength(beginWord, endWord, unexplored);
        if (length == 0)  return answer;
        // DFS to find all paths
        vector<string> path(length);  path[0] = beginWord;
        findPaths(unexplored, 0, length, answer, path, endWord);
        return answer;
    }

    void findPaths(unordered_set<string>& unexplored, int curr, int const& length,
                   vector<vector<string> >& answer, vector<string>& path, string const& endWord) {
        if (curr == length - 1) {
            if (path[curr] == endWord)  answer.push_back(path);
        } else {
            string word = path[curr];
            for (int i = 0; i < word.size(); ++i) {
                char oriCh = word[i];
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    if (ch == oriCh)  continue;
                    word[i] = ch;
                    if (unexplored.find(word) != unexplored.end()) {
                        unexplored.erase(word);   path[curr + 1] = word;
                        findPaths(unexplored, curr + 1, length, answer, path, endWord);
                        unexplored.insert(word);
                    }
                }
                word[i] = oriCh;
            }
        }
    }

    int getLength(string beginWord, string endWord, unordered_set<string> unexplored) {
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

int main() {
	string beginWord = "hit", endWord = "cog";
	vector<string> wordList;
	wordList.push_back("hot");  wordList.push_back("dot");
	wordList.push_back("dog");  wordList.push_back("lot");
	wordList.push_back("log");  wordList.push_back("cog");

	Solution s;
	vector<vector<string> > answer = s.findLadders(beginWord, endWord, wordList);
    for (vector<string> path : answer) {
        for (string str : path)  cout << str << " ";
        cout << endl;
    }
	return 0;
}