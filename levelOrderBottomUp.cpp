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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> tmp;
            TreeNode* node;
            int s = q.size();
            for (int i = 0 ; i < s; i++){
                node = q.front();
                q.pop();
                if (node->left)q.push(node->left);
                if (node->right)q.push(node->right);
                tmp.push_back(node->val);
            }
            res.push_back(tmp);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
