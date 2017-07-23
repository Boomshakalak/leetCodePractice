class Solution {
    unordered_map<string,bool> map;
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dic;
        for (auto x : wordDict)dic.insert(x);
        return find(s,dic);
    }
    bool find(string& s, unordered_set<string>& dic){
        if (map.count(s)) return map[s];
        if (s.empty()) return true;
        for (int i = 1 ; i <= s.size();i++){
            string tmp = s.substr(0,i);
            string tmp2 = s.substr(i);
            if (dic.count(tmp) && find(tmp2,dic)) {
                map[s] = true;
                return true;
            }
        }
        map[s] = false;
        return false;
    }

};
