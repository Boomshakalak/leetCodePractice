class Solution {
public:
    int reverse(int x) {
        long long res = x%10 ;
        while (x/=10){
            res=x%10+res*10;
        }
        return (res<INT_MIN || res>INT_MAX) ? 0 : res;
                }
};