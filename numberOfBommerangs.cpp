class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int res = 0;
        int k = points.size();
        for (int i = 0 ; i < k; i++){
            unordered_map<int,int> dis;
            for (int j = 0 ;  j < k ; j++){
                int dx = points[i].first -points[j].first;
                int dy = points[i].second - points[j].second;
                int d = dx*dx+dy*dy;
                dis[d]++;
            }
            for (auto x : dis){
                res += x.second*(x.second-1);
            }
        }
        return res;
    }
};
