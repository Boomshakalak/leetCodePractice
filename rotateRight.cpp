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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        int len = 1;
        ListNode* nHead;
        ListNode* cur = head;
        while (cur->next){
            cur = cur->next;
            len++;
        }
        cur->next = head;
        k = k%len;
        int pass = len - k;
        while(pass--){
            cur = cur->next;
        }
        nHead = cur->next;
        cur->next = NULL;
        return nHead;
    }
};
