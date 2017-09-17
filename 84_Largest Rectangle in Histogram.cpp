// Given n non-negative integers representing the histogram's bar height where the width 
// of each bar is 1, find the area of largest rectangle in the histogram.

// For example,
// Given heights = [2,1,5,6,2,3],
// return 10.

// 单调栈
// 首先我们要想到对于任意一个bar，我们想找以它为最高边的最大矩形，其实就是找它左右两边第一个小于它高度的bar的位置
// 单调递增栈可以很方便的找到这两个bar的位置，栈里面保存当前还未在右边找到小于它高度的bar
// 当新元素小于栈顶元素，表示栈内有元素已经找到右边第一个小于它高度的bar的位置，可以开始pop
// 栈内元素的前一个元素即是它左边第一个小于它高度的bar
// 每次pop计算以当前bar为最高高度的矩形的面积
class Solution {
public:
  int largestRectangleArea(vector<int>& heights) {
  	if (heights.empty())  return 0;
  	heights.push_back(0);
  	int max_area = 0, cur_index, width;
  	vector<int> stack;
  	for (int i = 0; i < heights.size(); ++i) {
  		while (!stack.empty() && heights[stack.back()] > heights[i]) {
  			cur_index = stack.back();  stack.pop_back();
  			width = stack.empty() ? i : i - stack.back() - 1;
  			max_area = max(max_area, heights[cur_index] * width);
  		}
  		stack.push_back(i);
  	}
  	return max_area;
  }
};