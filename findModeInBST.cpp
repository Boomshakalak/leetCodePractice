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
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        inorder(root,res);
        return res;
    }
    void inorder(TreeNode* root,vector<int>& res){
        if (!root) return;
        inorder(root->left,res);
        if (!prev || root->val != prev->val){
            prev = root;
            count = 1;
        }
        else count++;
        if (max < count){
            max = count;
            res.clear();
            res.push_back(root->val);
        }
        else if ( max == count){
            res.push_back(root->val);
        }
        inorder(root->right,res);
    }
private:
    int max = 0;
    int count = 0;
    TreeNode* prev = NULL;
};
