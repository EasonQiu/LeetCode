#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0 || prices.size() == 1) return 0;

        int left=0, right=0, profits=0;
        while (right + 1 < prices.size()){
            while (prices[right+1] > prices[right] && right + 1 < prices.size()){
                right++;
            }
            if (left == right){
                left = ++right;
            }else {
                profits += prices[right] - prices[left];
                left = ++right;
            }
        }

        return profits;
    }
};

int main() {
    int a[] = {3,2,6,8,4,9};
    vector<int> prices(a, a+6);

    Solution s;
    cout << s.maxProfit(prices);

    return 0;
}