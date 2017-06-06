class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        int dp[m][n] = {0};
        for (int i = 0; i < m ; ++i){
            for (int j = 0 ; j < n ; ++j){
                if (i == 0 && j ==0)dp[0][0] = grid[0][0];
                else if (i == 0) dp[i][j] = dp[i][j-1]+grid[i][j];
                else if (j == 0) dp[i][j] = dp[i-1][j]+grid[i][j];
                else
                    dp[i][j] = min(dp[i][j-1],dp[i-1][j])+grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};
