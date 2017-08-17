class Solution {
public:
    int rob(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return root->val;
        if (!root->left) return max(root->val+rob(root->right->left)+rob(root->right->right),rob(root->right));
        if (!root->right) return max(root->val+rob(root->left->left)+rob(root->left->right),rob(root->left));
        return max(root->val+rob(root->right->left)+rob(root->right->right)+rob(root->left->left)+rob(root->left->right),rob(root->left)+rob(root->right));
    }
};


class Solution {
    vector<int> helper(TreeNode* node) {
        vector<int> res(2, 0);
        if (node == nullptr) return res;

        vector<int> left = helper(node->left);
        vector<int>  right = helper(node->right);

        res[0] = max(left[0], left[1]) + max (right[0], right[1]);
        res[1] = node->val + left[0] + right[0];

        return res;
    }
public:
    int rob(TreeNode* root) {
        vector<int> res = helper(root);
        return max(res[0], res[1]);
    }
};
