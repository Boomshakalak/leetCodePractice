class Solution {
public:
    string removeDuplicateLetters(string s) {
        int count[26] ={0};
        for (auto x : s)count[x-'a']++;
        string res;
        unordered_set<char> occur;
        for (auto t : s){
            if (!occur.count(t)){
                while (res.size() && count[res.back()-'a']>1 && res.back() > t){
                    count[res.back()-'a']--;
                    occur.erase(res.back());
                    res.pop_back();
                }
                res.push_back(t);
                occur.insert(t);
            }
            else count[t-'a']--;
        }
        return res;
    }
};
