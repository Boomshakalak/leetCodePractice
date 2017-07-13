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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* cur  = head;
        ListNode* evenHead;
        ListNode* odd = head;
        ListNode* even;
        int count =1;
        while(cur->next){
            count++;
            cur = cur->next;
            if (count == 2) evenHead = even = cur;
            else if (count%2) {
                odd->next = cur;
                odd=odd->next;
            }
            else {
                even->next = cur;
                even = even->next;
            }
        }
        odd->next = evenHead;
        even->next = NULL;
        return head;
    }
};
