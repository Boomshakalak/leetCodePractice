class Solution {

public:
    unordered_map<int,int> cal;
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_set<int> res;
        int count = 0;
        dfs(root,res,count);
        return vector<int>(res.begin(),res.end());
    }
    int dfs(TreeNode* root,unordered_set<int>& res, int& count){
        if (!root) return 0;
        int sum = root->val+dfs(root->left,res,count)+dfs(root->right,res,count);
        cal[sum]++;
        if (cal[sum] == count)res.insert(sum);
        if (cal[sum] > count){
            res.clear();
            res.insert(sum);
            count = cal[sum];
        }
        return sum;
    }
};
