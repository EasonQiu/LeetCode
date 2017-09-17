// Implement int sqrt(int x).

// Compute and return the square root of x.

// find the position whose next number^2 is larger than x
class Solution {
public:
  int mySqrt(int x) {
  	long left = 0, right = x / 2 + 1, mid, square1, square2;
  	while (left + 1 < right) {
  		mid = left + (right - left) / 2;
  		square1 = mid * mid;
  		square2 = (mid + 1) * (mid + 1);
  		if (square1 <= x && square2 > x) {
  			return mid;
  		} else if (square1 <= x && square2 <= x) {
  			left = mid;
  		} else {
  			right = mid;
  		}
  	}
  	square1 = left * left;
  	square2 = (left + 1) * (left + 1);
  	if (square1 <= x && square2 > x) {
  		return left;
  	} else {
  		return right;
  	}
  }
};