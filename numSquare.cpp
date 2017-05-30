class Solution {
public:
    int numSquares(int n) {
        static vector<int> dp({0});
        int cur;
        while ( (cur=dp.size()) <= n+1){
            int tmp = INT_MAX;
            for (int i = 1 ; i*i <= cur; ++i){
                tmp = min(tmp,dp[cur-i*i]+1);
            }
            dp.push_back(tmp);
        }
        return dp[n];
    }
};
