class Solution {
public:
   int searchInsert(vector<int>& nums, int target) {
    int l = 0;
    int r = nums.size()-1;
    while(l<=r){
        int m = l+((r-l)>>1);
        if (nums[m] < target) l = m+1;
        else r = m-1;
}
    return l;

    }
};

// Just for the enhancement of the knowledge how to set interval bounds


class Solution {
public:
   int searchInsert(vector<int>& nums, int target) {
    int l = 0;
    int r = nums.size();
    while(l<r){ //left inclusive and right exclusive
        int m = l+((r-l)>>1);
        if (nums[m] < target) l = m+1;
        else r = m;
}
    return l;

    }
};
