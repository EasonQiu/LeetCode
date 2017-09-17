#include <iostream>
#include <vector>
#include <string>
using namespace std;

// leetcode上面sort没法用得小心可以自己写一个
bool comparator (string &lhs, string &rhs) {
    return lhs + rhs >= rhs + lhs;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if (nums.empty())  return "";
        // sort the numbers in the array
        vector<string> number(nums.size());
        for (int i = 0; i < nums.size(); ++i)  number[i] = to_string(nums[i]);
        sort(number.begin(), number.end(), comparator);
        // concatenate
        string ans = "";
        for (string &val : number)  ans += val;
        // find fisrt non-0 position
        int pos = 0;
        while (pos < ans.size() && ans[pos] == '0')  ++pos;
        return pos == ans.size() ? "0" : ans.substr(pos);
    }
};

// https://discuss.leetcode.com/topic/33467/c-4ms-with-explanation-o-n-log-n-time
class Solution2 {
public:
    string largestNumber(vector<int>& nums) {
    	if (nums.size() == 0)  return "";
    	vector<string> strs(nums.size());
    	for (int i = 0; i < nums.size(); ++i)  strs[i] = to_string(nums[i]);
        quickSort(strs, 0, strs.size() - 1);
    	if (strs[0] == "0")  return "0";
        string ans = "";
        for (string val : strs)  ans += val;
        return ans;
    }

    void quickSort(vector<string>& strs, int left, int right) {
    	if (left >= right)  return;
    	int pos = partition(strs, left, right);
    	quickSort(strs, left, pos - 1);
    	quickSort(strs, pos + 1, right);
    	return;
    }

    int partition(vector<string>& strs, int left, int right) {
    	string pivot = strs[right];
    	int i = left, j = right - 1;
    	while (i <= j) {
    		while ( i <= j && strs[i] + pivot >= pivot + strs[i] )  ++i;
    		while ( i <= j && strs[j] + pivot <= pivot + strs[j] )  --j;
    		if (i < j)  swap(strs[i], strs[j]);
    	}
    	swap(strs[i], strs[right]);
    	return i;
    }
};

int main() {
	vector<int> nums = {3, 30, 34, 5, 9};

	Solution s;
	cout << s.largestNumber(nums) << endl;

	return 0;
}