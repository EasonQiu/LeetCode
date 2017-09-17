// Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

// For example,
// Given [[0, 30],[5, 10],[15, 20]],
// return 2.


class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> starts, ends;
        for (Interval &span : intervals) {
            starts.push_back(span.start);
            ends.push_back(span.end);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        int rooms = 0;
        int j = 0;
        for (int i = 0; i < starts.size(); ++i) {
            // ++j: don't need ++rooms, cuz one interval ends before it starts
            (starts[i] < ends[j]) ? ++rooms : ++j;
        }
        return rooms;
    }
};