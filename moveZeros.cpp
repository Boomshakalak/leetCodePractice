class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int m =0;
        for(int i = 0 ; i < nums.size();++i){
            if (nums[i]) nums[m++] = nums[i];
        }
        for (;m<nums.size();++m){
            nums[m]=0;
        }
    }
};