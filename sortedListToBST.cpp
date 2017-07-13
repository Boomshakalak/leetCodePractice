/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return NULL;
        ListNode* m = findHalf(head);
        TreeNode* p = new TreeNode(m->val);
        if (head == m) return p;
        p->left = sortedListToBST(head);
        p->right = sortedListToBST(m->next);
        return p;
    }
    ListNode* findHalf(ListNode* a){
        if (!a) return NULL;
        ListNode* fast = a;
        ListNode* slow = a;
        ListNode* pre = slow;
        while(fast && fast->next){
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;
        return slow;
    }
};
