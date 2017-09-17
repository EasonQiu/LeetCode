// A sequence of number is called arithmetic if it consists of at least three elements 
// and if the difference between any two consecutive elements is the same.

// For example, these are arithmetic sequence:
// 1, 3, 5, 7, 9
// 7, 7, 7, 7
// 3, -1, -5, -9
// The following sequence is not arithmetic.
// 1, 1, 2, 5, 7

// A zero-indexed array A consisting of N numbers is given. A slice of that array is any 
// pair of integers (P, Q) such that 0 <= P < Q < N.
// A slice (P, Q) of array A is called arithmetic if the sequence:
// A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.
// The function should return the number of arithmetic slices in the array A.

// Example:
// A = [1, 2, 3, 4]
// return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] itself.

// 解法：类似467. Unique Substrings in Wraparound String，其实不需要那个array
//      每次只需要保存每个slice的最大长度，根据排列组合求出不同的解

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3)  return 0;
        int diff = A[1] - A[0];
        int len = 2;
        int ans = 0;
        for (int i = 2; i < A.size(); ++i) {
            int curr_diff = A[i] - A[i - 1];
            if (curr_diff == diff) {
                ++len;
                ans += len - 2;
            } else {
                len = 2;
                diff = curr_diff;
            }
        }
        return ans;
    }
};

class Solution {
public:
  int numberOfArithmeticSlices(vector<int>& A) {
  	if (A.size() <= 2)  return 0;
    vector<int> slices;
    // base case
    int diff = A[1] - A[0], curr_len = 2;
    // fill the array
    for (int i = 2; i < A.size(); ++i) {
    	if (A[i] - A[i - 1] == diff) {
    		++curr_len;
    	} else {
    		if (curr_len >= 3) slices.push_back(curr_len);
    		curr_len = 2;
    		diff = A[i] - A[i - 1];
    	}
    }
    if (curr_len >= 3)  slices.push_back(curr_len);
    // compute the number of solutions
    int count = 0;
    for (int len : slices) {
    	count += (len - 1) * (len - 2) / 2;
    }
    // final result
    return count;
  }
};