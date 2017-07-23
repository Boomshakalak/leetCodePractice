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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return NULL;
        if (root->val == key){
            if (!root->right){
                delete root;
                return root->left;
            }
            else{
                TreeNode* right = root->right;
                while(right->left)right = right->left;
                swap(right->val,root->val);
                root->right = deleteNode(root->right,key);
            }
        }
        else if (root->val < key) root->right = deleteNode(root->right,key);
        else root->left = deleteNode(root->left,key);
        return root;
    }
};
