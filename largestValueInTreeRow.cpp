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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> res;
        if (!root) return res;
        q.push(root);
        while(!q.empty()){
            int tmp = INT_MIN;
            int s = q.size();
            for (int i = 0 ; i < s; i++){
                TreeNode* t = q.front();
                tmp = max(tmp,t->val);
                q.pop();
                if (t->left)q.push(t->left);
                if (t->right)q.push(t->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
};
