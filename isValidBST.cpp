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
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        return isValidBST(root->left)&&check(root)&&isValidBST(root->right);
    }
    bool check(TreeNode* root){
        if (!prev){
            prev = root;
            return true;
        }
        if (prev->val >= root->val) return false;
        prev = root;
        return true;
    }

private:
    TreeNode* prev = NULL;
};
