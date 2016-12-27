class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> vit(3);
        int tar,idx1,idx2;
        int sum;
        if (nums.size()<3) return res;
        sort(nums.begin(),nums.end());
        for (int i =0;i<nums.size()-2;i++){
            tar=-nums[i];
            idx1=i+1;
            idx2=nums.size()-1;
            while(idx1<idx2){
                sum = nums[idx1] + nums[idx2];
                if (sum<tar)idx1++;
                else if (sum>tar) idx2--;
                else
                {
                    vit[0]=nums[i];
                    vit[1]=nums[idx1];
                    vit[2]=nums[idx2];
                    res.push_back(vit);
                    while (idx1<idx2 && nums[idx1] == vit[1])idx1++;
                    while (idx1<idx2 && nums[idx2] == vit[2])idx2--;
                }
                while ((i+2)<nums.size() && nums[i]==nums[i+1])i++;
            }
        }
        return res;
    }
};