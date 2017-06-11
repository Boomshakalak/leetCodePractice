class Solution {
public:
    bool canJump(vector<int>& nums) {
        int end = nums.size()-1;
        int lastIndex = end;
        int preIndex = -1;
        while (preIndex != lastIndex){
            preIndex = lastIndex;
            for ( int runner = end; runner >=0; runner--){
            if (nums[runner]+runner >= end && runner < lastIndex){
                lastIndex = runner;
            }
            end = lastIndex;
        }
        }
        return lastIndex==0;
    }
};
