class trie_node {
public:
    trie_node(){
        branch = vector<trie_node*>(26,NULL);
        end = false;
    }
    vector<trie_node*> branch;
    bool end;
};
class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new trie_node();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
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

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search_node(root,0,word);
    }
    bool search_node(trie_node* root,int i ,string& word){
        if (!root) return false;
        if (i == word.size()) return root->end;
        char x = word[i];
        if (x != '.'){
            int idx = x - 'a';
            return root->branch[idx]?search_node(root->branch[idx],i+1,word):false;
        }
        else{
            for (int j = 0 ; j < 26; j++){
                if (search_node(root->branch[j],i+1,word)) return true;
            }
            return false;
        }
    }
    trie_node* root;
};
