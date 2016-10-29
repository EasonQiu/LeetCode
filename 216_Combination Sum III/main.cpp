#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    void search(int k, int n, vector<vector<int>> &results, vector<int> &oneresult, vector<bool> & flag){
        if (k >= 1 && n >= 1){

            if (k == 1 && flag[n]){
                if (oneresult.size() == 0 && n <= 9){
                    oneresult.push_back(n);
                    results.push_back(oneresult);
                    oneresult.pop_back();
                }else if (n > oneresult[oneresult.size() -1] && n <= 9){
                    oneresult.push_back(n);
                    results.push_back(oneresult);
                    oneresult.pop_back();
                }
            }else if (k > 1){
                for (int i = 1; i <= min(9, n); i++){
                    if (flag[i]){
                        if (oneresult.size() == 0){
                            oneresult.push_back(i);  flag[i] = false;
                            search(k-1, n-i, results, oneresult, flag);
                            oneresult.pop_back();  flag[i] = true;
                        }else if (i > oneresult[oneresult.size() -1]){
                            oneresult.push_back(i);  flag[i] = false;
                            search(k-1, n-i, results, oneresult, flag);
                            oneresult.pop_back();  flag[i] = true;
                        }
                    }
                }
            }

        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> results;
        vector<int> oneresult;
        vector<bool> flag(10,true);
        search(k, n, results, oneresult, flag);
        return results;
    }
};

int main() {
    Solution s;
    s.combinationSum3(2,18);

    return 0;
}