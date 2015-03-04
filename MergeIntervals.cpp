/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
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
 bool compare(Interval i1, Interval i2)
 {
     return i1.start < i2.start;
 }
class Solution {
    
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        if(intervals.empty())
            return intervals;
            
        
        sort(intervals.begin(), intervals.end(), compare);
        vector<Interval> ret;
        
        for(int i = 0; i < intervals.size(); i++)
        {
            if(i == 0)
                ret.push_back(intervals[0]);
            else
            {
                int laststart = ret[ret.size() - 1].start;
                int lastend = ret[ret.size() - 1].end;
                if(intervals[i].start <= lastend)
                {
                    laststart = min(laststart, intervals[i].start);
                    lastend = max(lastend, intervals[i].end);
                    ret[ret.size() - 1].start = laststart;
                    ret[ret.size() - 1].end = lastend;
                }
                else
                    ret.push_back(intervals[i]);
            }
        }
        
        
        return ret;
    }
};
