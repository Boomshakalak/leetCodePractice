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

    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int left = len(root->left);
        int right = len(root->right);
        int res = left + right;
        return max(res,max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)));
    }
    int len(TreeNode* root){
        int left,right;
        if (!root) return 0;
        left = len(root->left);
        right = len(root->right);
        return max(left,right)+1;
    }
};

class Solution {
public:
    int res = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        len(root);
        return res;
    }
    int len(TreeNode* root){
        int left,right;
        if (!root) return 0;
        left = len(root->left);
        right = len(root->right);
        res = max(res,left+right);
        return max(left,right)+1;
    }
};
