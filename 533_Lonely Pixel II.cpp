// Given a picture consisting of black and white pixels, and a positive integer N, find the number of black pixels located at some specific row R and column C that align with all the following rules:

// Row R and column C both contain exactly N black pixels.
// For all rows that have a black pixel at column C, they should be exactly the same as row R
// The picture is represented by a 2D char array consisting of 'B' and 'W', which means black and white pixels respectively.

// Example:
// Input:                                            
// [['W', 'B', 'W', 'B', 'B', 'W'],    
//  ['W', 'B', 'W', 'B', 'B', 'W'],    
//  ['W', 'B', 'W', 'B', 'B', 'W'],    
//  ['W', 'W', 'B', 'W', 'B', 'W']] 

// N = 3
// Output: 6
// Explanation: All the bold 'B' are the black pixels we need (all 'B's at column 1 and 3).
//         0    1    2    3    4    5         column index                                            
// 0    [['W', 'B', 'W', 'B', 'B', 'W'],    
// 1     ['W', 'B', 'W', 'B', 'B', 'W'],    
// 2     ['W', 'B', 'W', 'B', 'B', 'W'],    
// 3     ['W', 'W', 'B', 'W', 'B', 'W']]    
// row index

// Take 'B' at row R = 0 and column C = 1 as an example:
// Rule 1, row R = 0 and column C = 1 both have exactly N = 3 black pixels. 
// Rule 2, the rows have black pixel at column C = 1 are row 0, row 1 and row 2. They are exactly the same as row R = 0.


class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        if (picture.empty())  return  0;
        int row = picture.size(), col = picture[0].size();
        int col_count[col] = {};
        unordered_map<string, int> row_count;  // <rowString, num_of_rows>
        for (int i = 0; i < row; ++i) {
            string pattern = "";
            for (int j = 0; j < col; ++j) {
                if (picture[i][j] == 'B')  ++col_count[j];
                pattern += picture[i][j];
            }
            ++row_count[pattern];
        }
        int count = 0;
        for (auto &pair : row_count) {
            if (pair.second != N)  continue;
            int row_B = 0, cur_count = 0;
            for (int j = 0; j < col; ++j) {
                if (pair.first[j] == 'W')  continue;
                if (++row_B > N) {
                    cur_count = 0;  break;
                }
                if (col_count[j] == N)  cur_count += N;
            }
            count += cur_count;
        }
        return count;
    }
};