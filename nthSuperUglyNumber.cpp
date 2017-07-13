class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int m = primes.size();
        vector<int> idx(m);
        vector<int> candidate(m,1);
        vector<int> res(n);
        int next = 1;
        for (int i = 0 ; i < n ; i++){
            res[i] = next;
            next = INT_MAX;
            for (int j = 0 ; j < m ; j++){
                if (candidate[j] == res[i]) candidate[j] =res[idx[j]++]*primes[j];
                next = min(next,candidate[j]);
            }
        }
        return res[n-1];
    }
};
