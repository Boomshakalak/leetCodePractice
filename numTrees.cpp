class Solution {
public:
    int numTrees(int n) {
        int k = res.size();
        if (n < res.size())return res[n];
        for (int i = 3; i <= n; i++){
            int tmp = 0;
            for (int j = 0; j < i ; j++){
                tmp += res[i-j-1]*res[j];
            }
            res.push_back(tmp);
        }
        return res[n];
    }
private:
    vector<int> res = {1,1,2};
};
