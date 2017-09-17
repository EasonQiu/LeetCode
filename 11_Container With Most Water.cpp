// Given n non-negative integers a1, a2, ..., an, where each represents a point at 
// coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i 
// is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, 
// such that the container contains the most water.

// Note: You may not slant the container and n is at least 2.


// Use v[low, high] indicates the volume of container with low and high. suppose height[low] 
// < height[high], then we move low to low+1, that means we ingored v[low, high-1],v[low, high-2],
// etc, if this is safe, then the algorithm is right, and it's obvious that v[low, high-1],
// high[low, high-2]...... can't be larger than v[low, high] since its width can't be larger 
// than high-low, and its height is limited by height[low].


class Solution {
public:
  int maxArea(vector<int>& height) {
  	if (height.size() <= 1)  return 0;
  	int max_area = INT_MIN;
  	int left = 0, right = height.size() - 1;
  	while (left < right) {
  		max_area = max(max_area, (right - left) * min(height[left], height[right]));
  		(height[left] < height[right]) ? ++left : --right;
  	}
  	return max_area;
  }
};