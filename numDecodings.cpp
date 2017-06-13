//Very ugly code but work, the corner case about '0' is much more frustrating than  DP itself!
class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        int n = s.size();
        if (!n)return 0;
        int dp[n] = {0};
        int tail = n-1;
        if (s[tail]>'0') dp[tail]=1;
        else {
            tail--;
            if (tail < 0) return 0;
            if (s[tail] <= '2' && s[tail] >'0') dp[tail] = 1;
            else return 0;
        }
        for (int i = tail-1; i >= 0;i--){
            if (s[i] == '0') dp[i] = 0;
            else if ((s[i] > '2')||(s[i]=='2' && s[i+1]>'6'))dp[i]=dp[i+1];
            else{
                if (s[i+1]=='0'){
                    if (s[i] <= '2' && s[i] >'0')dp[i]=dp[i+2];
                    else return 0;
                }
                else if (i+2 < n) dp[i]=dp[i+1]+dp[i+2];
                else dp[i] = dp[i+1]+1;
            }
        }
        return dp[0];
    }
};
