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
    ListNode* swapPairs(ListNode* head) {
        ListNode* fake = new ListNode(0);
        fake->next = head;
        int count = 0;
        ListNode* cur = head;
        ListNode* pre = fake;
        vector<ListNode*> tmp;
        while (cur){
            tmp.push_back(cur);
            cur = cur->next;
            if (tmp.size() == 2){
                pre->next = tmp[1];
                pre = tmp[0];
                tmp[0]->next = tmp[1]->next;
                tmp[1]->next = tmp[0];
                tmp.clear();
            }

        }
        return fake->next;
    }
};
