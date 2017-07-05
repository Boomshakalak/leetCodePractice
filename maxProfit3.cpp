class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        vector<int> first = getprofit(prices);
        vector<int> second = getsecondprofit(prices);
        for (int i = 0; i < prices.size();i++){
            res = max(res,first[i]+second[i]);
        }
        return res;
    }
    vector<int> getsecondprofit(vector<int>& prices){
        vector<int> res(prices.size());
        int peak = INT_MIN;
        int maxprofit = 0;
        for (int i = prices.size()-1; i >=0; i--){
            if (prices[i]>peak) peak = prices[i];
            maxprofit = max(maxprofit,peak-prices[i]);
            res[i]= maxprofit > 0? maxprofit:0;
        }
        return res;
    }
    vector<int> getprofit(vector<int>& prices){
        vector<int> res;
     	int valley = INT_MAX;
        int maxprofit = 0;
        for (int i = 0 ; i < prices.size(); i++){
            if (prices[i] < valley) valley = prices[i];
            maxprofit = max(maxprofit,prices[i]-valley);
            res.push_back((maxprofit>0?maxprofit:0));
        }
        return res;
    }
};

//Generalize to k transactions

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), num = 2;
        if (n <= 1) return 0;
        vector<vector<int> > dp(num + 1, vector<int>(n, 0));
        for (int k = 1; k <= num; k++) {
            int temp = dp[k - 1][0] - prices[0];
            for (int i = 1; i < n; i++) {
                dp[k][i] = max(dp[k][i - 1], prices[i] + temp);
                temp = max(temp, dp[k - 1][i] - prices[i]);
            }
        }
        return dp[num][n - 1];
    }
};
