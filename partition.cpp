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
    ListNode* partition(ListNode* head, int x) {
        if (!head ||!head->next) return head;
        ListNode* cur = head;
        ListNode* a = new ListNode(0);
        ListNode* b = new ListNode(0);
        ListNode* pa = a;
        ListNode* pb = b;
        while(cur){
            if (cur->val < x){
                pa->next = cur;
                pa = pa->next;
            }
            else {
                pb->next = cur;
                pb = pb->next;
            }
            cur = cur->next;
        }
        pb->next =NULL;
        pa->next = b->next;
        return a->next;
    }
};
