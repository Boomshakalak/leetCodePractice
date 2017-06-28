class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        if (k < 0) return 0;
        int count = 0;
        int i =0,j = 1;
        while( j < nums.size()){
            while(nums[j] < nums[i]+k && j < nums.size())j++;
            if (j == nums.size()) break;
            if (nums[j] == nums[i]+k){
                count++;
            while( (j < nums.size()-1) && nums[j+1] == nums[j]){j++;}
            j++;
            }
            while(nums[i+1] == nums[i]){
                i++;
            }
            i++;
            if (i == j)j++;
        }
        return count;
    }
};
