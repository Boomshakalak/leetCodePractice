class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int valley = INT_MAX;
        for (auto x : prices){
            if (x < valley) valley = x;
            if (x-valley > profit) profit = x-valley;
        }
        return profit>0?profit:0;
    }
};
