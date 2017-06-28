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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root,res);
        return res;
    }
    void inorder(TreeNode* cur, vector<int> & v){
        if (!cur) return;
        inorder(cur->left,v);
        v.push_back(cur->val);
        inorder(cur->right,v);
    }

};
