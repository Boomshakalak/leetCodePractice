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
    struct node{
        int value;
        int index;
    };
    vector<int> findRightInterval(vector<Interval>& intervals) {
        vector<node> interval(intervals.size()+1);
        for (int i = 0; i < intervals.size();i++)interval[i] = {intervals[i].start,i};
        auto cmp = [](const node& a, const node& b){return a.value < b.value;};
        sort(interval.begin(),interval.end()-1,cmp);  // We keep a separate last one in case we cannot find the index
        interval.back().index = -1;
        vector<int> res(intervals.size());
        for (int i = 0; i < intervals.size();i++){
            node cur = {intervals[i].end,0};
            auto itr = lower_bound(interval.begin(),interval.end()-1,cur,cmp);
            res[i] = itr->index;
        }
        return res;
    }
};
