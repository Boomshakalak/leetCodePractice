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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return NULL;
        ListNode* cur = head;
        int len = 0;
        while(cur){
            cur = cur->next;
            len++;
        }
        if (n == len) return head->next;
        ListNode* pre;
        cur = head;
        for(int i = 0 ; i < len - n; i++){
            pre = cur;
            cur = cur->next;
        }
        pre->next = cur->next;
        return head;
    }
};
