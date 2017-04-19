#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.empty())  return vector<Interval>();
        vector<Interval> ans;
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){ return a.start < b.start; });
        ans.push_back(intervals[0]);
        for (unsigned int i = 1; i < intervals.size(); ++i) {
        	if (intervals[i].start <= ans.back().end) {
        		ans.back().end = max(ans.back().end, intervals[i].end);
        	} else {
        		ans.push_back(intervals[i]);
        	}
        }
        return ans;
    }
};

int main() {
	Interval i1(1, 3), i2(2, 6), i3(8, 10), i4(15, 18);
	vector<Interval> intervals;
	intervals.push_back(i1);  intervals.push_back(i2);
	intervals.push_back(i3);  intervals.push_back(i4);

	Solution s;
	vector<Interval> ans = s.merge(intervals);

	for (Interval i : ans)  cout << i.start << " " << i.end << endl;
	return 0;
}