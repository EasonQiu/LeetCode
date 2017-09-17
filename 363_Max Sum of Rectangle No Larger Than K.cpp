// Given a non-empty 2D matrix matrix and an integer k, find the max sum of a rectangle 
// in the matrix such that its sum is no larger than k.

// Example:
// Given matrix = [
//   [1,  0, 1],
//   [0, -2, 3]
// ]
// k = 2
// The answer is 2. Because the sum of rectangle [[0, 1], [-2, 3]] is 2 and 2 is the max 
// number no larger than k (k = 2).

// Note:
// The rectangle inside the matrix must have an area > 0.
// What if the number of rows is much larger than the number of columns?

// 同max sum of subarray no larger than k
class Solution {
public:
  int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
		if (matrix.empty())  return 0;
		int row = matrix.size(), col = matrix[0].size();
		int max_sum = INT_MIN;
		for (int l = 0; l < col; ++l) {
			int arr[row] = {};
			for (int r = l; r < col; ++r) {
				// update arr array
				for (int i = 0; i < row; ++i) {
					arr[i] += matrix[i][r];
				}
				// find the max sum no larger than k in an arr array
				int pre_sum = 0;
				set<int> sums;  
				sums.insert(0); // base case, subarray of [0, i]
				for (int i = 0; i < row; ++i) {
					pre_sum += arr[i];
					auto pos = sums.lower_bound(pre_sum - k);
					if (pos != sums.end()) {
						max_sum = max(max_sum, pre_sum - *pos);
					}
					sums.insert(pre_sum);
				}
			}
		}
		return max_sum;
	}
};