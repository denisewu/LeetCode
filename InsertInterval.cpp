/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        int left = -1, right = -1, pos = -1;
        Interval newIntv = newInterval;
        for(int i = 0; i < intervals.size(); i++)
        {
            if(intervals[i].start <= newIntv.end && intervals[i].end >= newIntv.start)
            {
                newIntv.start = min(intervals[i].start, newIntv.start);
                newIntv.end = max(intervals[i].end, newIntv.end);
                right = i;
                if(left == -1)
                    left = i;
            }
            else if(intervals[i].start > newIntv.end && pos == -1)
            {
                pos = i;
            }
        }
        if(left > -1)
        {
            intervals.erase(intervals.begin() + left, intervals.begin() + right + 1);
            intervals.insert(intervals.begin() + left, newIntv);
        }
        else if(pos > -1)
        {
            intervals.insert(intervals.begin() + pos, newIntv);
        }
        else
        {
            intervals.push_back(newIntv);
        }
        return intervals;
    }
};
