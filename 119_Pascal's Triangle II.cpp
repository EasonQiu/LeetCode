#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0)  return vector<int>{1};
        if (rowIndex == 1)  return vector<int>{1, 1};
        vector<int> row{1, 1};
        int level = 1;
        while (++level <= rowIndex) {
            vector<int> next(level + 1, 1);
            for (int i = 1; i < level; ++i) {
                next[i] = row[i] + row[i - 1];
            }
            swap(row, next);
        }
        return row;
    }
};

int main() {
    Solution s;
    s.getRow(5);

    return 0;
}