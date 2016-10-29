#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;

        if (prices.size() > 1){
            vector<int> buyPrices(prices.size()), sellPrices(prices.size());
            int lowestPrice = prices[0];
            int highestPrice = prices[prices.size() - 1];

            buyPrices[0] = prices[0];
            for (int i = 1; i <= prices.size() - 2; i++){
                if (prices[i] < lowestPrice){
                    lowestPrice = prices[i]; buyPrices[i] = lowestPrice;
                }else {
                    buyPrices[i] = lowestPrice;
                }
            }

            sellPrices[prices.size()-2] = prices[prices.size()-1];
            for (int i = prices.size() - 2; i >= 1; i--){
                if (prices[i] > highestPrice){
                    highestPrice = prices[i]; sellPrices[i - 1] = highestPrice;
                }else {
                    sellPrices[i - 1] = highestPrice;
                }
            }

            for (int i = 0; i <= prices.size() - 2; i++){
                if (sellPrices[i] - buyPrices[i] > max) {
                    max = sellPrices[i] - buyPrices[i];
                }
            }
        }

        return max;
    }
};

int main() {
    int a[] = {1,2};
    vector<int> prices(a, a+2);

    Solution s;
    cout << s.maxProfit(prices);

    return 0;
}