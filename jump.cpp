class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int end = nums.size()-1;
        int lastIndex = end;
        int count = 0;
        while (end > 0){
            for ( int runner = end; runner >=0; runner--){
            if (nums[runner]+runner >= end){
                lastIndex = runner;
            }
        }
        end = lastIndex;
        count++;
    }
       return count;
    }
};
