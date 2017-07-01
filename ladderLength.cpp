//wordlist to hashtable is always right for you
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet;
        for (string x : wordList)wordSet.insert(x);
        if (!wordSet.count(endWord)) return 0;
        queue<string> qs;
        qs.push(beginWord);
        int step = 1;
        while(!qs.empty()){
            int l = qs.size();
            step++;
            for (int j = 0 ; j < l; j++){
                string t = qs.front();
                qs.pop();
                auto itr = wordSet.begin();   // something need to know
                while(itr!=wordSet.end()){
                    string s = *itr;
                    if (isNeighbor(t,s)){
                        if (s == endWord) return step;
                        itr = wordSet.erase(itr);
                        qs.push(s);
                    }
                    else itr++;
                }
            }
        }
        return 0;
    }
    bool isNeighbor(string curword, string word){
        if (curword.size() != word.size()) return false;
        int count = 0;
        for (int i = 0 ; i < curword.size();i++){
            if (curword[i]!=word[i])count++;
            if (count > 1) return false;
        }
        return true;
    }
};
