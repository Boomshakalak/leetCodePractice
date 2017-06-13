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
    int findTilt(TreeNode* root) {
        int sum = 0;
        getSum(root,sum);
        return sum;
    }
    int getSum(TreeNode* root,int &sum){
        if (!root) return 0;
        int left = getSum(root->left,sum);
        int right = getSum(root->right,sum);
        sum += abs(left-right);
        return root->val+left+right;
    }
};
