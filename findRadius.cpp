class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        if (!heaters.size()) return 0;
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int hti = 0;
        int res = 0;
        for (int i = 0 ; i < houses.size(); ++i){
            while (hti+1 < heaters.size() && (abs(heaters[hti+1] - houses[i]) <= abs(heaters[hti] - houses[i]))) {
                hti++;
            }
            int candidate = abs(heaters[hti] - houses[i]);
            res = max(res,candidate);
        }
        return res;
    }
};
