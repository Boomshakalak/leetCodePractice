/* This algorithm is a dumpy one but maitain full information of the whole list*/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,vector<int>> um;
        for (int i = 0 ; i < nums.size() ; i++){
            um[nums[i]].push_back(i);
            for (int j = 0 ; j <um[nums[i]].size()-1;j++){
                if (i-um[nums[i]][j] <= k) return true;
            }
        }
        return false;
    }
};
