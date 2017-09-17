// Given two binary strings, return their sum (also a binary string).

// For example,
// a = "11"
// b = "1"
// Return "100".

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        string ans = "";
        while (i >= 0 || j >= 0 || carry == 1) {
            int n1 = (i >= 0) ? a[i] - '0' : 0;
            int n2 = (j >= 0) ? b[j] - '0' : 0;
            n1 += n2 + carry;
            carry = n1 / 2;  n1 = n1 % 2;
            ans = to_string(n1) + ans;
            --i;  --j;
        }
        return ans;
    }
};