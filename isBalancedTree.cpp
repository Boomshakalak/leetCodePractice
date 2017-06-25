/**
In this balanced tree, balance is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. An intuitive way is to calculate
the depth of every subtree, but it needs 2 recursions to finish the task which is not effficient.
"In order to be away from the scenario of recursion in recursion, the only way is to think about adding a variable so that one recursive process can perform two functionalities at the same time."
This might help to understand how to do it in one recursion.
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
    bool isBalanced(TreeNode* root) {
        bool res = true;
        depth_helper(root,res);
        return res;
    }
    int depth_helper(TreeNode* root,bool & res){
        if (!res) return -1;
        if (!root) return 0;
        int lh = depth_helper(root->left,res);
        int rh = depth_helper(root->right,res);
        if (abs(lh-rh)>1) res = false;
        return 1 + max(depth_helper(root->left,res),depth_helper(root->right,res));
    }

};
