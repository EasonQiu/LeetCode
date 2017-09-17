// The gray code is a binary numeral system where two successive values differ in only one bit.

// Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

// For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

// 00 - 0
// 01 - 1
// 11 - 3
// 10 - 2
// Note:
// For a given n, a gray code sequence is not uniquely defined.

// For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

// For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.


class Solution { // consider like DP
public:
    vector<int> grayCode(int n) {
        vector<int> ans{0};
        int size = 0;
        while (++size <= n) {
            vector<int> copy(ans);
            reverse(copy.begin(), copy.end());
            for (int i = 0; i < copy.size(); ++i) {
                copy[i] |= 1 << (size - 1);
                ans.push_back(copy[i]);
            }
        }
        return ans;
    }
};