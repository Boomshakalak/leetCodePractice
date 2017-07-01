/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        queue<TreeLinkNode*> qt;
        qt.push(root);
        while(!qt.empty()){
            int k = qt.size();
            for (int i = 0 ; i < k; i++){
            TreeLinkNode* cur = qt.front();
            qt.pop();
            if (cur->left) qt.push(cur->left);
            if (cur->right) qt.push(cur->right);
            if (i == k-1) break;
            cur->next = qt.front();

            }

        }
    }
};
