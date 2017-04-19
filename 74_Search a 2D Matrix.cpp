#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        // return false when there is 0 row or 0 column
        if (matrix.size() == 0) return false;
        else if (matrix[0].size() == 0) return false;
        int m = (int)matrix.size(), n = (int)matrix[0].size(), size = m * n;
        int left =  0, right = size - 1, mid, i, j;
        while (left <= right) {
            mid = left + (right - left) / 2;
            i = mid / n, j = mid % n;
            if (left == right)  return matrix[i][j] == target;
            if (matrix[i][j] < target) {
                left  = mid + 1;  // target in the second half
            } else {
                right = mid;  // target in the first half
            }
        }
        return false;
    }
};

int main() {
    int a[] = {1,2,3,4}, b[] = {6,7,8,9}, c[] = {1};
    vector<int> row1(a,a+4), row2(b,b+4), row3(c,c+1);
    vector<vector<int> > nums;
    nums.push_back(row3);
    // nums.push_back(row1);  nums.push_back(row2);

    Solution s;
    cout << s.searchMatrix(nums,1);

    return 0;
}