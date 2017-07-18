class trie_node {
public:
    trie_node(){
        branch = vector<trie_node*>(26,NULL);
        end = false;
    }
    vector<trie_node*> branch;
    bool end;
};
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new trie_node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        int i = 0 ;
        trie_node* cur = root;
        while (i < word.size()){
            int idx = word[i++]-'a';

            if (cur->branch[idx]){
                cur = cur->branch[idx];
            }
            else {
                cur->branch[idx] = new trie_node();
                cur = cur->branch[idx];
            }
            if ( i == word.size()) cur->end = true;
        }
    }
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int i = 0;
        trie_node* cur = root;
        while(i < word.size()){
            int idx = word[i++]-'a';
            if (!cur->branch[idx]) return false;
            cur = cur->branch[idx];
            if (i == word.size() && !cur->end) return false;
        }
        return true;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int i = 0;
        trie_node* cur = root;
        while(i < prefix.size()){
            int idx = prefix[i++]-'a';
            if (!cur->branch[idx])return false;
            cur = cur->branch[idx];
        }
        return true;
    }
private:
    trie_node* root;
};
