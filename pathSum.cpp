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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(root,sum,res,tmp);
        return res;
    }
    void dfs(TreeNode* node, int sum, vector<vector<int>> &res,vector<int> & tmp){
        if (!node) return;
        tmp.push_back(node->val);
        if (!(node->left) && !(node->right) && sum == node->val) res.push_back(tmp);
        dfs(node->left,sum-node->val,res,tmp);
        dfs(node->right,sum-node->val,res,tmp);
        tmp.pop_back();
    }
};
