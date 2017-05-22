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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);

    }
    TreeNode* helper(vector<int>& nums,int start,int end){
        int size = end-start;
        if (size < 0) return NULL;
        if (size == 0) return new TreeNode(nums[start]);
        int m = (start + end)/2;
        TreeNode* p = new TreeNode(nums[m]);
        p->left = helper(nums,start,m-1);
        p->right = helper(nums,m+1,end);
        return p;
    }
};
