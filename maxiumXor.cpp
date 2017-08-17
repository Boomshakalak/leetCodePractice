
class Solution {

public:
    class trie_node{
public:
    trie_node* next[2];
    trie_node(){next[0] = NULL;next[1] = NULL;};
};
    trie_node* buildTree(vector<int>& nums){
        trie_node* root = new trie_node();
        for (int num : nums){
            trie_node* cur = root;
            for (int i = 30 ; i >=0 ; i--){
                int bit = ((num>>i)&1);
                if (!cur->next[bit]){
                    cur->next[bit] = new trie_node();
                }
                cur = cur->next[bit];
            }
        }
        return root;
    }
    int getXorRes(trie_node* root,int num){
        int res = 0;
        trie_node* cur = root;
        for (int i = 30; i >=0 ; i-- ){
            int bit = (num>>i)&1;
            if (cur->next[bit^1]){
                res+=1<<i;
                cur = cur->next[bit^1];
            }
            else
                cur = cur->next[bit];
        }
        return res;
    }
    int findMaximumXOR(vector<int>& nums) {
        trie_node* root = buildTree(nums);
        int res = 0;
        for (int num : nums) res = max(res,getXorRes(root,num));
        return res;
    }
};
