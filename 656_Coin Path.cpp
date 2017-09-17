// Given an array A (index starts at 1) consisting of N integers: A1, A2, ..., AN and an integer B. The integer B denotes that from any place (suppose the index is i) in the array A, you can jump to any one of the place in the array A indexed i+1, i+2, …, i+B if this place can be jumped to. Also, if you step on the index i, you have to pay Ai coins. If Ai is -1, it means you can’t jump to the place indexed i in the array.

// Now, you start from the place indexed 1 in the array A, and your aim is to reach the place indexed N using the minimum coins. You need to return the path of indexes (starting from 1 to N) in the array you should take to get to the place indexed N using minimum coins.

// If there are multiple paths with the same cost, return the lexicographically smallest such path.

// If it's not possible to reach the place indexed N then you need to return an empty array.

// Example 1:
// Input: [1,2,4,-1,2], 2
// Output: [1,3,5]
// Example 2:
// Input: [1,2,4,-1,2], 1
// Output: []
// Note:
// Path Pa1, Pa2, ..., Pan is lexicographically smaller than Pb1, Pb2, ..., Pbm, if and only if at the first i where Pai and Pbi differ, Pai < Pbi; when no such i exists, then n < m.
// A1 >= 0. A2, ..., AN (if exist) will in the range of [-1, 100].
// Length of A is in the range of [1, 1000].
// B is in the range of [1, 100].

// If there are two path to reach n, and they have the same optimal cost, 
// then the longer path is lexicographically smaller.
// coins[i]: 从A[0..i]需要花费的min coins
// steps[i]: 从A[0..i]需要花费的min coins所选择的steps数
// prev[i]:  从A[0..i]需要花费的min coins所选择的上一个index
// 先后顺序：coins小，coins一致steps大，
class Solution {
public:
    vector<int> cheapestJump(vector<int>& A, int B) {
        int size = A.size();
        vector<int> coins(size, INT_MAX), steps(size), prev(size);
        coins[0] = A[0];  prev[0] = -1;  steps[0] = 1;
        for (int i = 1; i < size; ++i) {
            if (A[i] == -1)  continue;
            for (int j = max(0, i - B); j < i; ++j) {
                if (A[j] == -1 || coins[j] == INT_MAX)  continue;
                if ((coins[j] + A[i] < coins[i]) ||
                    (coins[j] + A[i] == coins[i] && steps[j] + 1 > steps[i])) {
                    coins[i] = coins[j] + A[i];
                    prev[i] = j;
                    steps[i] = steps[j] + 1;
                }
            }
        }
        if (coins[size - 1] == INT_MAX)  return vector<int>();
        vector<int> ans(steps[size - 1]);
        int i = ans.size() - 1, j = size - 1;
        while (i >= 0) {
            ans[i--] = j + 1;  j = prev[j];
        }
        return ans;
    }
};