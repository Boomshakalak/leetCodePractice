class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int k = nums.size()-1;
        // if (nums[k] <= 0) return nums[k]*nums[k-1]*nums[k-2];
        // if (nums[k-1] <= 0) return nums[k]*nums[0]*nums[1];
        // if (nums[k-2] <= 0) return nums[k]*nums[0]*nums[1];
        // The above lines can explain the final return value as a detailed conditons
        return max(nums[0]*nums[1]*nums[k],nums[k]*nums[k-1]*nums[k-2]); // or return max(nums[0]*nums[1],nums[k-1]*nums[k-2])*nums[k];
    }
};
