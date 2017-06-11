/* Intuitive but really not space effficient in other word stupid */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> tmp;
        int res = 0 ;
        int counter = 0;
        for (int i = 0; i < nums.size();i++){
            if (i > 0 && nums[i]==nums[i-1])counter++;
            else
                counter = 0;
            if (counter < 2){
                res++;
                tmp.push_back(nums[i]);
        }
        }
        nums = tmp;
        return res;
    }
};
//This method is kind of smart, the if-condition equivalent to we have three same numbers, 2 pointers!
int removeDuplicates(vector<int>& nums) {
    int i = 0;
    for (int n : nums)
        if (i < 2 || n > nums[i-2])
            nums[i++] = n;
    return i;
}
