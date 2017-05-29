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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int a = preorder.size()-1;
        return getRoot(preorder,0,a,inorder,0,a);
    }
    TreeNode* getRoot(vector<int> & preorder,int f, int l,vector<int>& inorder,int m, int n){
        if (f > l) return NULL;
        int v = preorder[f];
        TreeNode* np = new TreeNode(v);
        int tmp;
        for (int i = m ; i <= n;++i){
            if (inorder[i] == v) {
                tmp = i;
                break;
            }
        }
        int leftsize = tmp - m;
        int rightsize = n - tmp;
        np->left = getRoot(preorder,f+1,f+leftsize,inorder,m,tmp-1);
        np->right = getRoot(preorder,f+leftsize+1,l,inorder,tmp+1,n);
        return np;
    }
};
