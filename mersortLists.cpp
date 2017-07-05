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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* a;
        ListNode* b;
        half(a,b,head);
        a = sortList(a);
        b = sortList(b);
        return merge(a,b);
    }
    void half(ListNode*&a, ListNode*& b,ListNode* head){
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev;
        while (fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        a = head;
        b = slow;
        prev->next = NULL;
    }
    ListNode* merge(ListNode*& a, ListNode*& b){
        if (!a) return b;
        if (!b) return a;
        ListNode* temp;
        if (a->val < b->val){
            temp = a;
            temp->next = merge(a->next,b);
        }
        else {
            temp = b;
            temp->next = merge(a,b->next);
        }
        return temp;
    }
};
