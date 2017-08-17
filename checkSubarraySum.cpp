class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        vector<int> sum(nums.size()+1,0);
        unordered_set<int> remainder;
        int rem;
        for (int i =1 ; i < sum.size();i++){
            sum[i] = sum[i-1]+nums[i-1];
            if(k){
                rem = sum[i]%k;
                if(!rem && i > 1) return true;
            }
            if (!k) rem = sum[i];
            if ((k && remainder.count(rem)) || (!k && remainder.count((-1)*rem))) return true;
            else remainder.insert(rem);
        }
        return false;
    }
};
