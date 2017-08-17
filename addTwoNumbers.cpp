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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1;
        stack<int> s2;
        while(l1){
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2){
            s2.push(l2->val);
            l2 = l2->next;
        }
        int carry = 0 ;
        int sum = 0;
        ListNode* pre = NULL;
        while(!s1.empty() ||!s2.empty() || carry){
            sum = 0;
            if (!s1.empty()){
                sum+=s1.top();
                s1.pop();
            }
            if (!s2.empty()){
                sum+=s2.top();
                s2.pop();
            }
            if (carry){
                sum+=carry;
            }
            ListNode* cur = new ListNode(sum%10);
            carry = sum/10;
            cur->next = pre;
            pre = cur;
        }
        return pre;
    }
};
