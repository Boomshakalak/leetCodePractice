class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        if (!nums.size()) return 0;
        int res = 0;
        for(int i=0;i<32;i++) {
            int one = 0;
            for(int j=0;j<nums.size();j++) {
                if ( (nums[j] & (1 << i)) != 0) one++;
            }
            res += one * (nums.size() - one);
        }
        return res;
    }
};
