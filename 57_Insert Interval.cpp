#include <iostream>
#include <vector>
#include <cmath>
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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> ans;
        bool isMerge = false;
        unsigned int i = 0;
        while (i < intervals.size()) {
            ans.push_back(intervals[i++]);
            if (!isMerge && newInterval.start <= ans.back().end) {
                isMerge = true;
                if (newInterval.end < ans.back().start) { // newInterval doesn't have overlap
                    ans.insert(--ans.end(), newInterval);
                    continue;
                }
                ans.back().start = min(ans.back().start, newInterval.start);
                ans.back().end = max(ans.back().end, newInterval.end);
                while (i < intervals.size() && intervals[i].start <= ans.back().end) {
                    ans.back().end = max(ans.back().end, intervals[i++].end);
                }
            }
        }
        if (!isMerge)  ans.push_back(newInterval);
        return ans;
    }
};

int main() {
	Interval i1(1, 5), i2(6, 9), i3(0, 0);
	vector<Interval> intervals;
	intervals.push_back(i1);  
    // intervals.push_back(i2);

	Solution s;
	vector<Interval> ans = s.insert(intervals, i3);

	for (Interval i : ans)  cout << i.start << " " << i.end << endl;
	return 0;
}