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
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        return dfs(root,0,sum)+pathSum(root->left,sum)+pathSum(root->right,sum);
    }
    int dfs(TreeNode* node ,int pre,int target){
        if (!node) return 0;
        pre = pre + node->val;
        return (pre==target)+dfs(node->left,pre,target)+dfs(node->right,pre,target);
    }
};
