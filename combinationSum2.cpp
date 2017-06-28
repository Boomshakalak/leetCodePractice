class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        sort(candidates.begin(),candidates.end());
        combSum(res,cur,candidates,0,target);
        return res;
    }
    void combSum(vector<vector<int>> & res, vector<int> & cur,vector<int>& candidates,int k,int target){
        if (target == 0) res.push_back(cur);
        else{
            for (int i = k ;( i < candidates.size()) && ( candidates[i] <= target) ; i++){
                if(i && candidates[i] == candidates[i-1]&&i>k) continue; //This line is critical important for removing duplicates, think it carefully!!!
                cur.push_back(candidates[i]);
                combSum(res,cur,candidates,i+1,target-candidates[i]);
                cur.pop_back();
            }
        }
    }
};
