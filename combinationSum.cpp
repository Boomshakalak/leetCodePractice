class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        sort(candidates.begin(),candidates.end());
        comb(res,candidates,tmp,target,0);
        return res;
    }
    void comb(vector<vector<int>> & res,vector<int> & candidates, vector<int> & tmp, int target, int begin){
        if (!target) res.push_back(tmp);
        else
            for (int i = begin; i < candidates.size() && candidates[i] <= target;++i){
                tmp.push_back(candidates[i]);
                comb(res,candidates,tmp,target-candidates[i],i);
                tmp.pop_back();
            }
    }
};
