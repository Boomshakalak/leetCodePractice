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
    vector<TreeNode*> generateTrees(int n) {
        if (!n) return vector<TreeNode*>();
        return buildTree(1, n);
    }

    vector<TreeNode*> buildTree(int s, int e){
        if (s > e) return vector<TreeNode*>(1,NULL);
        vector<TreeNode*> res;
        for (int i = s ; i<= e; i++){
            auto left = buildTree(s,i-1);
            auto right = buildTree(i+1,e);
            for (int m = 0 ; m < left.size();m++){
                for (int n = 0; n < right.size();n++){
                    TreeNode* root = new TreeNode(i);
                    root->left = left[m];
                    root->right = right[n];
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};
