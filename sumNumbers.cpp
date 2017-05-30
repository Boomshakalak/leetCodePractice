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
    int sumNumbers(TreeNode* root) {
        res = 0;
        tmp = 0;
        if (!root) return 0;
        dfs(root);
        return res;
    }
    void dfs(TreeNode* cur){
        tmp = tmp*10 + cur->val;
        if (!cur->left && !cur->right) {
            res+=tmp;
            return;
        }
        if (cur->left) {dfs(cur->left);tmp = tmp/10;}
        if (cur->right) {dfs(cur->right);tmp = tmp/10;}

    }
private:
    int res;
    int tmp;
};
