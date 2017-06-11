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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        dfs(root,sum,false);
        return sum;
    }
    void dfs(TreeNode* node, int & sum,bool left){
        if (!node) return;
        if (left && !node->left && !node->right) sum += node->val;
        dfs(node->left,sum,true);
        dfs(node->right,sum,false);
    }
};
