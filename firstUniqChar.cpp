class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> count(26,-1);
        for (int i = 0 ; i < s.size(); ++i){
            if (count[s[i]-'a'] == -1) count[s[i]-'a'] = i;
            else count[s[i]-'a']=-2;
        }
        int res = INT_MAX;
        for (int i = 0 ; i < 26; i++){
            if (count[i]<res && count[i] >=0) res=count[i];
        }
        return res == INT_MAX ? -1 : res;
    }
};
