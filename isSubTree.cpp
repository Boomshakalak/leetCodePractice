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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!s || !t) return false;
        return (check(s,t) || isSubtree(s->left,t) || isSubtree(s->right,t));
    }
    bool check(TreeNode* s, TreeNode* t){
        if (s == NULL || t == NULL) return s == t;
        return (s->val == t->val) && check(s->left,t->left) && check(s->right,t->right);
    }
};
