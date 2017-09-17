// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"
// Write the code that will take a string and make this conversion given a number of rows:

// string convert(string text, int nRows);
// convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".


class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> rows(numRows);
        int i = 0, size = s.size();
        while (i < size) {
            for (int j = 0; j < numRows && i < size; ++j)  rows[j] += s[i++];
            for (int j = numRows - 2; j >= 1 && i < size; --j)  rows[j] += s[i++];
        }
        string ans = "";
        for (string &str : rows)  ans += str;
        return ans;
    }
};