// Given a positive integer n, return the number of all possible attendance records with length n, 
// which will be regarded as rewardable. The answer may be very large, return it after mod 109 + 7.

// A student attendance record is a string that only contains the following three characters:

// 'A' : Absent.
// 'L' : Late.
// 'P' : Present.
// A record is regarded as rewardable if it doesn't contain more than one 'A' (absent) or more 
// than two continuous 'L' (late).

// Example 1:
// Input: n = 2
// Output: 8 
// Explanation:
// There are 8 records with length 2 will be regarded as rewardable:
// "PP" , "AP", "PA", "LP", "PL", "AL", "LA", "LL"
// Only "AA" won't be regarded as rewardable owing to more than one absent times. 


class Solution {
public:
  int checkRecord(int n) {
  	if (n == 0)  return 0;
  	int P[n][2] = {}, L1[n][2] = {}, L2[n][2] = {}, A[n] = {};
  	// base case
  	P[0][0] = 1;  L1[0][0] = 1;  A[0] = 1;
  	// fill the array
  	for (int i = 1; i < n; ++i) {
  		P[i][0]  = ((P[i - 1][0] + L1[i - 1][0]) % 1000000007 + L2[i - 1][0]) % 1000000007; // P, 0A before
  		P[i][1]  = ((P[i - 1][1] + L1[i - 1][1]) % 1000000007 + 
  								(L2[i - 1][1] + A[i - 1]) % 1000000007) % 1000000007; // P, 1A before
  		L1[i][0] = P[i - 1][0]; // 1L, 0A before
  		L1[i][1] = (P[i - 1][1] + A[i - 1]) % 1000000007; // 1L, 1A before
  		L2[i][0] = L1[i - 1][0]; // 2L, 0A before
  		L2[i][1] = L1[i - 1][1]; // 2L, 1A before
  		A[i] = P[i][0]; // A
  	}
  	// get the answer
  	n--;
  	int ans1 = (P[n][0] + P[n][1]) % 1000000007;
  	int ans2 = (L1[n][0] + L1[n][1]) % 1000000007;
  	int ans3 = (L2[n][0] + L2[n][1]) % 1000000007;
  	int ans = ((ans1 + ans2) % 1000000007 + (ans3 + A[n]) % 1000000007) % 1000000007;
  	return ans;
  }
};