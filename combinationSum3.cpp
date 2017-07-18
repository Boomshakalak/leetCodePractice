class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> tmp;
        getAns(res,tmp,k,n);
        return res;
    }
    void getAns(vector<vector<int>>& res, vector<int> &tmp, int k , int n){
        if (tmp.size() == k && n) return;
        if (tmp.size() == k && !n)res.push_back(tmp);
        else{
            for (int i = tmp.size()?tmp.back()+1:1; i <=9;i++){
                if ((n-i)<0) return;
                tmp.push_back(i);
                getAns(res,tmp,k,n-i);
                tmp.pop_back();
            }
        }
    }
};
