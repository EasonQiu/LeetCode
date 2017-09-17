#include <iostream>
#include <vector>#include <iostream>
#include <stack>
using namespace std;


// 用单调递减栈，因为我们要找某个height左边和右边第一个大于它的height
// 如果找到一组，就以stack.top()为底边计算可容纳水的大小
// stack左边存严格大于它的index，碰到右边大于等于它的height会被pop
// corner case两height相等时已被cover即高度差为0，还要考虑左边为空情况
class Solution {
public:
  int trap(vector<int>& height) {
    if (height.empty())  return 0;
    stack<int> stack;
    int max_water = 0, bottom;
    for (int i = 0; i < height.size(); ++i) {
      // pop heights lower than the current one
      while (!stack.empty() && height[stack.top()] <= height[i]) {
        bottom = height[stack.top()];  stack.pop();
        if (stack.empty())  break;
        max_water += (min(height[stack.top()], height[i]) - bottom) * (i - stack.top() - 1);
      }
      // push the current one
      stack.push(i);
    }
    return max_water;
  }
};

int main() {
	int a[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	vector<int> height(a,a+12);

	Solution s;
	cout << s.trap(height) << endl;
	return 0;
}