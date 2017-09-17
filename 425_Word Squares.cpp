// Given a set of words (without duplicates), find all word squares you can build from them.

// A sequence of words forms a valid word square if the kth row and column read the exact same string, where 0 ≤ k < max(numRows, numColumns).

// For example, the word sequence ["ball","area","lead","lady"] forms a word square because each word reads the same both horizontally and vertically.

// b a l l
// a r e a
// l e a d
// l a d y
// Note:
// There are at least 1 and at most 1000 words.
// All words will have the exact same length.
// Word length is at least 1 and at most 5.
// Each word contains only lowercase English alphabet a-z.

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
    vector<vector<string>> wordSquares(vector<string>& words) {
        root = new TrieNode();
        for (string &word : words)  addWord(word);
        int size = words[0].size();
        vector<vector<string> > ans;
        vector<string> square(size); // one solution of ans
        dfs(0, square, ans);
        return ans;
    }
    
    void dfs(int row, vector<string> &square, vector<vector<string> > &ans) {
        if (row == square.size()) {
            ans.push_back(square);  return;
        }
        // get all possible words with certain prefix
        string prefix = "";
        for (int i = 0; i <= row - 1; ++i)  prefix += square[i][row];
        vector<string> candidates = startWith(prefix);
        for (string &word : candidates) {
            square[row] = word;
            if (!isFitColumn(square, row))  continue;
            dfs(row + 1, square, ans);
        }
    }
    
    bool isFitColumn(vector<string> &square, int row) {
        for (int j = row + 1; j < square[0].size(); ++j) {  // check column by column
            TrieNode* node = root;
            for (int i = 0; i < row; ++i) {  // move to the node of last character 
                if (!node->childs[square[i][j] - 'a'])  return false;
                node = node->childs[square[i][j] - 'a'];
            }
            bool haveChilds = false;
            for (int k = 0; k < 26; ++k) { // check if this prefix has childs
                if (node->childs[k]) {
                    haveChilds = true;  break;
                }
            }
            if (!haveChilds)  return false;
        }
        return true;
    }
    
    // TrieTree part
    void addWord(string &word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->childs[ch - 'a'])  node->childs[ch - 'a'] = new TrieNode();
            node = node->childs[ch - 'a'];
        }
        node->word = word;
    }
    
    vector<string> startWith(string &prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            if (!node->childs[ch - 'a'])  return vector<string>();
            node = node->childs[ch - 'a'];
        }
        vector<string> ans;
        getAllWords(node, ans);
        return ans;
    }
    
    void getAllWords(TrieNode* node, vector<string> &ans) {
        if (node->word != "") {
            ans.push_back(node->word);
        } else {
            for (TrieNode* next : node->childs) {
                if (next) getAllWords(next, ans);
            }
        }
    }

private:
    TrieNode* root;
};