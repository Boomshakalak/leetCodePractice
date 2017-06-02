class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        sort(coins.begin(),coins.end());
        vector<int> dp(amount+1,INT_MAX);
        for (int i = 1; i <= amount; ++i){
            if (i < coins[0]) continue;
            for (auto x :coins)
            {
                if (i == x) {dp[i]=1;break;}
                if (i > x && dp[i-x]!=INT_MAX) dp[i]=min(dp[i],dp[i-x]+1);
            }
        }
        return dp[amount]==INT_MAX?-1:dp[amount];
    }
};
