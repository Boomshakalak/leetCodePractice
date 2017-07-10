class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        int len = prices.size();
        if (len<2) return 0;
        if (k>len/2) k = len/2;
        vector<int> hold(k+1,INT_MIN);
        vector<int> rele(k+1,0);
        for (int i=0; i<len; ++i){
            int cur = prices[i];
            for(int j=k; j>0; --j){
                rele[j] = max(rele[j],hold[j] + cur);
                hold[j] = max(hold[j],rele[j-1] - cur);
            }
        }
        return rele[k];
    }
};
