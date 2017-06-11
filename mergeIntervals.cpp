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
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const Interval &a,const Interval &b){return a.start < b.start;});
        for (int i = 1; i < intervals.size();){
            if (intervals[i].start <= intervals[i-1].end){
                intervals[i-1].end = max(intervals[i-1].end,intervals[i].end);
                intervals.erase(intervals.begin()+i);
            }
            else
                i++;
        }
        return intervals;
    }
};
