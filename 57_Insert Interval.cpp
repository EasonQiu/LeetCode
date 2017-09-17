// Given a set of non-overlapping intervals, insert a new interval into the intervals 
// (merge if necessary).
// You may assume that the intervals were initially sorted according to their start times.

// Example 1:
// Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

// Example 2:
// Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
// This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].


// 感想：慎用vector的erase函数，因为每执行一次要消耗O(n)的时间
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
        if (intervals.empty()) {
            intervals.push_back(newInterval);  return intervals;
        }
        // find the first interval whose end >= newInterval.start
        int i = 0;
        while (i < intervals.size() && intervals[i].end < newInterval.start) {
            ++i;
        }
        // merge is necessary
        if (i == intervals.size() || newInterval.end < intervals[i].start) {
            intervals.insert(intervals.begin() + i, newInterval);
            return intervals;
        } else {
            intervals[i].start = min(intervals[i].start, newInterval.start);
            intervals[i].end = max(intervals[i].end, newInterval.end);
        }
        // delete the following overlapped intervals
        int curr = i++;
        while (i < intervals.size() && intervals[i].start <= intervals[curr].end) {
            intervals[curr].end = max(intervals[curr].end, intervals[i].end);
            ++i;
        }
        intervals.erase(intervals.begin() + curr + 1, intervals.begin() + i);
        // final result
        return intervals;
    }
};

class Solution2 {
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