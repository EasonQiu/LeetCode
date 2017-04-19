#include <iostream>
#include <vector>#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> s;
        int max_water(0);
        int i(0);
        while (i<height.size()) {
            if (s.empty()||height[i]<=height[s.top()]) {
                s.push(i++);
            } else {
                int bottom=height[s.top()];
                s.pop();
                if (!s.empty())
                    max_water += (min(height[i], height[s.top()]) - bottom) * (i-s.top()-1);
            }
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
#include <stack>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> s;
        int max_water(0);
        int i(0);
        while (i<height.size()) {
            if (s.empty()||height[i]<=height[s.top()]) {
                s.push(i++);
            } else {
                int bottom=height[s.top()];
                s.pop();
                if (!s.empty())
                    max_water += (min(height[i], height[s.top()]) - bottom) * (i-s.top()-1);
            }
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