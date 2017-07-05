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
    void flatten(TreeNode* root) {
        pre = new TreeNode(0);
        preorder(root);
    }
    void preorder(TreeNode* root){
        if (!root) return;
        TreeNode* left = root->left;  //First you need to record the left children and the right children because in recursion they will be modified and missing
        TreeNode* right = root->right;
        pre->right = root;
        pre->left = NULL;
        pre = root; // In this manner the pre is working as a pointer of the flat linked tree leading all way down
        preorder(left);
        preorder(right);
    }
private:
    TreeNode* pre;
};
