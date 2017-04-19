#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> lines;
        vector<int> oneLine;
        rowIndex++;
        if (rowIndex <= 0){
            lines.clear();
        }else if (rowIndex == 1){
            oneLine.clear(); oneLine.push_back(1); lines.push_back(oneLine);
        }else if (rowIndex == 2){
            oneLine.clear(); oneLine.push_back(1); lines.push_back(oneLine);
            oneLine.clear(); oneLine.push_back(1); oneLine.push_back(1); lines.push_back(oneLine);
        }else {
            oneLine.clear(); oneLine.push_back(1); lines.push_back(oneLine);
            oneLine.clear(); oneLine.push_back(1); oneLine.push_back(1); lines.push_back(oneLine);
            for (int i = 2; i < rowIndex; i++){
                oneLine.clear(); oneLine.push_back(1);
                for (int j = 1; j <= i -1; j++){
                    oneLine.push_back(lines[i-1][j-1] + lines[i-1][j]);
                }
                oneLine.push_back(1); lines.push_back(oneLine);
            }
        }
        return oneLine;
    }
};

int main() {
    Solution s;
    s.getRow(5);

    return 0;
}