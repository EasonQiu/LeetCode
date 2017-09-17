// Given a sequence of words, check whether it forms a valid word square.

// A sequence of words forms a valid word square if the kth row and column read the exact same string, where 0 ≤ k < max(numRows, numColumns).

// Note:
// The number of words given is at least 1 and does not exceed 500.
// Word length will be at least 1 and does not exceed 500.
// Each word contains only lowercase English alphabet a-z.

// Input:
// [
//   "abcd",
//   "bnrt",
//   "crm",
//   "dt"
// ]

// Output:
// true

// Explanation:
// The first row and first column both read "abcd".
// The second row and second column both read "bnrt".
// The third row and third column both read "crm".
// The fourth row and fourth column both read "dt".

// Therefore, it is a valid word square.

class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        if (words.empty())  return false;
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j < words[i].size(); ++j) {
                if (j >= words.size())  return false;
                if (i >= words[j].size())  return false;
                if (words[i][j] != words[j][i])  return false;
            }
        }
        return true;
    }
};