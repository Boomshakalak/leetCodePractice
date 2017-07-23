class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> um;
        for (auto x : nums) um[x]++;
        vector<pair<int,int>> res;
        auto it =um.begin();
        for (int i = 0 ; i < k && i < n; i++){
            res.push_back(*it);
            it++;
        }
        sort(res.begin(),res.end(),[](pair<int,int>& a, pair<int,int>& b){ return a.second < b.second;});
        for (;it != um.end();it++){
            if ((*it).second > res[0].second) {
                res[0] = *it;
                sort(res.begin(),res.end(),[](pair<int,int>& a, pair<int,int>& b){ return a.second < b.second;});
            }
        }
        vector<int> ans;
        for (auto x : res)ans.push_back(x.first);
        return ans;
    }
};
