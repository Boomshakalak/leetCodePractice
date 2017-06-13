/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 // Leetcode is not hard as I expected it could be or I am better now? :)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        ListNode* p = new ListNode(0);
        ListNode* cur = p;
        auto cmp = [](ListNode* a,ListNode* b){return a->val > b->val; };
        priority_queue<ListNode*,vector<ListNode*>,decltype(cmp)> ql(cmp);
        for (auto x : lists){
            if(x)ql.push(x);
        }
        while(!ql.empty()){
            ListNode* tmp = ql.top();
            ql.pop();
            cur->next = tmp;
            cur = tmp;
            if (cur->next)ql.push(cur->next);
        }
        return p->next;
    }
};
