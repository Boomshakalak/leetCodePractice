class Solution {
public:
    string frequencySort(string s) {
        string res;
        unordered_map<char,int> um;
        for (auto x : s){
            um[x]++;
        }
        vector<pair<char,int>> stat;
        for (auto x : um)stat.push_back(x);
        sort(stat.begin(),stat.end(),[](pair<char,int>& a, pair<char,int>& b){return a.second > b.second;});
        for (auto x : stat){
            int count = x.second;
            while(count--){
                res.push_back(x.first);
        }

    }
        return res;
    }
};
