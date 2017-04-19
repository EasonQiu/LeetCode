#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if (n == 0) return 0;
        else if (n == 1) return triangle[0][0];

        vector<int> f(triangle[n - 1]);
        for (int i = n - 2; i >= 0; i--){
            for (int j = 0; j <= i; j++){
                f[j] = triangle[i][j] + min(f[j], f[j + 1]);
            }
        }

        return f[0];
    }

    int minimumTotal2(vector<vector<int>>& triangle) {
        if (triangle.size() == 0) return 0;
        else if (triangle.size() == 1) return triangle[0][0];

        for (int i = triangle.size()-2; i >= 0; i--){
            for (int j = 0; j < triangle[i].size(); j++){
                triangle[i][j] += min(triangle[i+1][j],triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
};

int main() {
    vector<vector<int>> triangle;
    int a1[] = {2};
    int a2[] = {3,4};
    int a3[] = {6,5,7};
    int a4[] = {4,1,8,3};
    triangle.push_back(vector<int>(a1,a1+1));
    triangle.push_back(vector<int>(a2,a2+2));
    triangle.push_back(vector<int>(a3,a3+3));
    triangle.push_back(vector<int>(a4,a4+4));

    Solution s;
    cout << s.minimumTotal(triangle) << endl;

    return 0;
}