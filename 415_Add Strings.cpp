// Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

// Note:

// The length of both num1 and num2 is < 5100.
// Both num1 and num2 contains only digits 0-9.
// Both num1 and num2 does not contain any leading zero.
// You must not use any built-in BigInteger library or convert the inputs to integer directly.


class Solution {
public:
    string addStrings(string num1, string num2) {
        if (num1.empty() || num2.empty())  return num1 + num2;
        int i = num1.size() - 1, j = num2.size() - 1;
        string ans = "";
        int carry = 0;
        while (i >= 0 || j >= 0) {
            int sum = carry + (i >= 0 ? num1[i] - '0' : 0) + (j >= 0 ? num2[j] - '0' : 0);
            ans += '0' + (sum % 10);
            carry = sum / 10;
            --i;  --j;
        }
        if (carry > 0)  ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};