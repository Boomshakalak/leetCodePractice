/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return NULL;
        if (map.count(head)) return map[head];
        RandomListNode* nnode = new RandomListNode(head->label);
        map[head] = nnode;
        nnode->next = copyRandomList(head->next);
        nnode->random = copyRandomList(head->random);
        return nnode;
    }
private:
    unordered_map<RandomListNode*,RandomListNode*> map;
};
