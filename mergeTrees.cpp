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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) return NULL;
        int sum = (t1?t1->val:0)+(t2?t2->val:0);
        TreeNode* p = new TreeNode(0);
        p->val = sum;
        p->left = mergeTrees(t1?t1->left:NULL,t2?t2->left:NULL);
        p->right = mergeTrees(t1?t1->right:NULL,t2?t2->right:NULL);
        return p;
    }
};
