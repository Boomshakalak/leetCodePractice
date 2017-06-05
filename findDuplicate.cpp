/* If there exists multiple duplicates in the array, the only duplicate will contribute more 1s on certain bits, as a result, we can say if we have unexpected more 1 on certain bit, the dupicate is 1 at that postion */
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int bit;
        int res = 0;
        for (bit = 1; bit < nums.size(); bit <<= 1){
            int count = 0;
            for (int i = 0 ; i < nums.size();i++){
                count += (nums[i]&bit)-(i&bit);
            }
            if (count > 0) res |=bit;
        }
        return res;
    }
};
