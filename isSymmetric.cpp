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
    bool isSymmetric(TreeNode* root) {
       if (root == NULL) return true;
       return helper(root->left,root->right);
    }
    bool helper(TreeNode* a,TreeNode* b){
        if (a == NULL && b == NULL) return true;
        if (a == NULL && b != NULL) return false;
        if (a != NULL && b == NULL) return false;
        if (a->val != b->val) return false;
        return helper(a->left,b->right) && helper(a->right,b->left);

    }
};
