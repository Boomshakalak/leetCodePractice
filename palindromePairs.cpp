class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string,int> um;
        vector<vector<int>> res;
        for ( int i = 0 ; i < words.size(); i++){
            string str = words[i];
            reverse(str.begin(),str.end());
            um[str] = i;
        }
        if (um.count("")){
            int k = um[""];
            for (int i = 0 ; i < words.size(); i++){
                if (isP(words[i]) && i != k)res.push_back({k,i});
            }
        }
        for (int i = 0 ; i < words.size(); i ++){
            for (int j = 0; j < words[i].size();j++){
                string left = words[i].substr(0,j);
                string right = words[i].substr(j);
                if (um.count(left) && isP(right) && um[left]!=i)res.push_back({i,um[left]});
                if (um.count(right) && isP(left) && um[right]!=i) res.push_back({um[right],i});
            }
        }
        return res;
    }
    bool isP(string s){
        if (s.size() < 2) return true;
        int i = 0 ;
        int j = s.size()-1;
        while(i<j){
            if (s[i++]!=s[j--]) return false;
        }
        return true;
    }
};
