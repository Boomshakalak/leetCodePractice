class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res = {{}};
        for (int i = 0 ; i < nums.size()){
            int count = 0 ;
            while(i+count < nums.size() && nums[i] == nums[i+count])count++;
            int curN = res.size();
            for (int j = 0 ; j < curN; j++){
                vector<int> temp = res[j];
                for (int k = 0; k < count;k++){
                    temp.push_back(nums[i]);
                    res.push_back(temp);
                }
            }
            i += count;
        }
        return res;
    }
};
