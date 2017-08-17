//define a dp array represents some kind of stuf ending at i is commonly used in DP 

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if (n < 3) return 0;
        int result = 0;
        vector<int> dp(n,0);
        if (A[1]-A[0] == A[2] - A[1])dp[2] = 1;
        result += dp[2];
        for (int i =3 ; i < n ; i++){
            if (A[i]-A[i-1] == A[i-1] - A[i-2]) dp[i] =dp[i-1]+1;
            result += dp[i];
        }
        return result;
    }
};
