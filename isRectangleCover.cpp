
class Solution {

public:
        struct myHash{
        size_t operator()(pair<int, int> val) const
        {
            string s = to_string(val.first)+","+to_string(val.second);
            hash<string> hf;
            return hf(s);
        }
    };
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        unordered_map<pair<int,int>,int,myHash> occur;
        int area = 0;
        vector<pair<int,int>> corner ={{0,1},{0,3},{2,3},{2,1}};
        int xmin = INT_MAX,xmax = INT_MIN,ymin = INT_MAX,ymax = INT_MIN;
        for (auto x : rectangles){
            for (auto point : corner){
                if (++occur[make_pair(x[point.first],x[point.second])] > 4) return false;
            }
            xmin = min(xmin,x[0]),xmax = max(xmax,x[2]),ymin = min(ymin,x[1]),ymax = max(ymax,x[3]);
            area += (x[2]-x[0])*(x[3]-x[1]);
        }
        if (area != (xmax-xmin)*(ymax-ymin)) return false;
        unordered_set<pair<int,int>,myHash> c = {{xmin,ymin},{xmax,ymin},{xmin,ymax},{xmax,ymax}};
        for (auto x : occur){
            if (x.second & 1) {
                if (!c.count(x.first)) return false;
                c.erase(x.first);
            }
        }
        return c.empty();
    }
};
