class Solution {
public:
    int arrangeCoins(int n) {
        long long  i ;
        long long sum = 0 ;
        for (i  = 1 ; sum <= n ; ++i){
            sum+=i;
        }
        return i-2;
    }
};