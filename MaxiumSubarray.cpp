class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0] ;
        int tmp = 0;
        for (auto x : nums){
            tmp+= x;
            if (tmp > sum) sum = tmp;
            if (tmp<0) tmp = 0;
        }
        return sum;
    }
};