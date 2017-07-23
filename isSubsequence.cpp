class Solution {
public:
    bool isSubsequence(string s, string t) {
        return findNextchar(s,t,0,0);
    }
    bool findNextchar(string& s, string& t, int is, int it){
        if (is == s.size()) return true;
        for (int i = it; i < t.size();i++){
            if (s[is] == t[i]) return findNextchar(s,t,is+1,i+1);
        }
        return false;
    }
};
