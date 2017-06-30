

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ts;
        if (!root) return ts;
        vector<int> tmp;
        dfs(root,tmp);
        return transfer(res);
    }
    void dfs(TreeNode* root,vector<int> &tmp){
        tmp.push_back(root->val);
        if (!root->left && !root->right)res.push_back(tmp);
        if (root->left) {dfs(root->left,tmp);tmp.pop_back();}
        if (root->right){dfs(root->right,tmp);tmp.pop_back();}
    }
    vector<string> transfer(vector<vector<int>> & res){
        vector<string> vs;
        for (auto x: res){
            string s;
            for ( int i = 0 ; i < x.size();i++ ){
                if (!i) s+=to_string(x[i]);
                else
                s = s+"->"+to_string(x[i]);
            }
            vs.push_back(s);
        }
        return vs;
    }
private:
    vector<vector<int>> res;
};
