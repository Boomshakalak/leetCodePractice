class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        vector<string> tmp;
        unordered_set<string> head,tail;
        unordered_set<string> dic;
        unordered_map<string,vector<string>> next;
        bool search4ward = true;
        for (auto x:wordList)dic.insert(x);
        dic.erase(beginWord);
        if (!dic.count(endWord)) return res;
        head.insert(beginWord);
        tail.insert(endWord);
        get(next,head,tail,dic,search4ward);
        tmp.push_back(beginWord);
        getPath(res,tmp,next,beginWord,endWord);
        return res;
    }
    void get(unordered_map<string,vector<string>>& next, unordered_set<string>& head, unordered_set<string>& tail,unordered_set<string>& dic, bool search4ward){
        if (head.size()> tail.size()) return get(next,tail,head,dic,!search4ward);
        if (!head.size()) return;
        bool done = false;
        unordered_set<string> immediate;
        for (auto x: head) dic.erase(x);
        for (auto word: head){
            int l = word.size();
            string temp = word;
            for (int i = 0; i < l ; i++){
                temp = word;
                for (int j = 0 ; j < 26;j++){
                    temp[i]='a'+j;
                    if (tail.count(temp)){
                        search4ward?next[word].push_back(temp):next[temp].push_back(word);
                        done = true;
                    }
                    else if (dic.count(temp)){
                        immediate.insert(temp);
                        search4ward?next[word].push_back(temp):next[temp].push_back(word);
                    }
                }
            }
        }
    if (!done) return get(next,immediate,tail,dic,search4ward);
    }
    void getPath(vector<vector<string>>& res,vector<string>& tmp, unordered_map<string,vector<string>>& next, string cur,string endWord){
        if (cur == endWord)res.push_back(tmp);
        else{
            for (auto x : next[cur]){
                tmp.push_back(x);
                getPath(res,tmp,next,x,endWord);
                tmp.pop_back();
            }
        }
    }
};
