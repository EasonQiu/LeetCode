#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int pos = digits.size()-1;
        digits[pos]++;
        while (digits[pos] >= 10){
            if (pos == 0){
                digits.push_back(0);
                for (int j = digits.size() -1; j >= 2; j--)
                    digits[j] = digits[j - 1];
                digits[0] = 1; digits[1] = 0;
            }else {
                digits[pos-1]++; digits[pos--] = 0;
            }
        }
        return digits;
    }
};

int main() {
    int a[3] = {9,9,9};
    vector<int> digits(a, a+3);

    Solution s;
    s.plusOne(digits);

    return 0;
}