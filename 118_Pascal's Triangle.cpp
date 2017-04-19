#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> lines;
        vector<int> oneLine;
        if (numRows <= 0){
            lines.clear();
        }else if (numRows == 1){
            oneLine.clear(); oneLine.push_back(1); lines.push_back(oneLine);
        }else if (numRows == 2){
            oneLine.clear(); oneLine.push_back(1); lines.push_back(oneLine);
            oneLine.clear(); oneLine.push_back(1); oneLine.push_back(1); lines.push_back(oneLine);
        }else {
            oneLine.clear(); oneLine.push_back(1); lines.push_back(oneLine);
            oneLine.clear(); oneLine.push_back(1); oneLine.push_back(1); lines.push_back(oneLine);
            for (int i = 2; i < numRows; i++){
                oneLine.clear(); oneLine.push_back(1);
                for (int j = 1; j <= i -1; j++){
                    oneLine.push_back(lines[i-1][j-1] + lines[i-1][j]);
                }
                oneLine.push_back(1); lines.push_back(oneLine);
            }
        }
        return lines;
    }
};

int main() {
    Solution s;
    s.generate(5);

    return 0;
}