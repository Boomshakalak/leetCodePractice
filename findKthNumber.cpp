

class Solution {
public:
    int findKthNumber(int n, int k) {
        int cur = 1;
        while(k > 0) {
            if(1 == k) return cur;
            int sum = calc(n, cur);
            if(k > sum) {
                k -= sum;
                cur = cur + 1;
            }
            else {
                k --;
                cur = cur * 10;
            }
        }
        return cur;
    }
    // calc return the count of the number no more than n with prefix x
    int calc(int n, int64_t x) {
        int ans = 0, t = 1;
        while(x <= n) {
            if(x + t - 1 <= n) ans += t;
            else ans += n - x + 1;
            x *= 10;
            t *= 10;
        }
        return ans;
    }
};
