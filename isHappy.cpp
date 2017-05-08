class Solution {
public:
    long long getSquareSum(int n){
        long long res = 0;
        while(n){
            res += (n%10)*(n%10);
            n /= 10;
        }
        return res;
    }
    bool isHappy(int n) {
        long long cur = getSquareSum(n);
        unordered_set<long long> us;
        while(us.find(cur) == us.end()){
            us.insert(cur);
            cur = getSquareSum(cur);
            
        }
        if (us.find(1)!=us.end()) return true;
        return false;
    }
};