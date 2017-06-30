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
    int maxPathSum(TreeNode* root) {
        int res = root->val ;
        depthsum(root,res);
        return res;
    }

//function keep track of the sum over one side and the variable res keep track of the total sum
    int depthsum(TreeNode* root,int& res){
        if (!root) return 0;
        int a = depthsum(root->left,res);
        int b = depthsum(root->right,res);
        res = max(res,a+b+root->val);
        return max(0,max(a,b)+root->val);

    }
};
