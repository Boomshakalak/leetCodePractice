/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* fake = new ListNode(0);
        fake->next = head;
        ListNode* pre = fake;
        ListNode* cur = head;
        while (cur){
            ListNode* np = cur->next;
            if (np && np->val == cur->val){
            while (np && np->val == cur->val){
                np = np->next;
            }
            cur = np;
            pre->next = cur;
        }
        else{
            pre = cur;
            cur = cur->next;
        }

        }
        return fake->next;
    }

};
