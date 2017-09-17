// Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.

// Note:

// The length of both num1 and num2 is < 110.
// Both num1 and num2 contains only digits 0-9.
// Both num1 and num2 does not contain any leading zero.
// You must not use any built-in BigInteger library or convert the inputs to integer directly.

// corner case: 1234, 0
class Solution {
public:
    string multiply(string num1, string num2) {
        int l1 = num1.size(), l2 = num2.size();
        vector<int> product(l1 + l2);
        for (int i = 0; i < l1; ++i) {
            for (int j = 0; j < l2; ++j) {
                product[l1 - i + l2 - j - 2] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        string ans = "";
        for (int i = 0; i < l1 + l2 - 1; ++i) {
            product[i + 1] += product[i] / 10;
            ans = char((product[i] % 10) + '0') + ans;
        }
        if (product[l1 + l2 - 1] > 0)  ans = to_string(product[l1 + l2 - 1]) + ans;
        int i = 0;
        while (i + 1 < ans.size() && ans[i] == '0')  ++i;
        return ans.substr(i);
    }
};