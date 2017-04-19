#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int ans = 0;
        int minPrice = INT_MAX;
        for(int i = 0; i < prices.size(); i++){
            minPrice = min(minPrice, prices[i]);
            ans = max(ans, prices[i] - minPrice);
        }
        return ans;
    }

    int maxProfit1(vector<int>& prices) {
        int n = prices.size(), ans = 0;
        // calculate the difference of two days
        vector<int> diff(n);
        for (int i = 1; i < n; ++i) {
            diff[i] = prices[i] - prices[i - 1];
        }
        // iterate the diff array
        int maxSum = 0;
        for (int i = 1; i < n; ++i) {
            maxSum = max(0, maxSum + diff[i]);
            ans = max(ans, maxSum);
        }
        return ans;
    }
};

int main() {
    int a[] = {7,1,5,3,6,4};
    vector<int> prices(a, a+6);

    Solution s;
    cout << s.maxProfit(prices) << endl;
    return 0;
}