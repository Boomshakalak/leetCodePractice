class Solution {
public:
    void sortColors(vector<int>& nums) {
        int bucket[3] = {0};
        for (int x : nums)bucket[x]++;
        int i = 0;
        while(bucket[0]||bucket[1]||bucket[2]){
            if (bucket[0]){nums[i++]=0;bucket[0]--;}
            else if (bucket[1]){nums[i++]=1;bucket[1]--;}
            else
                {
                    nums[i++]=2;
                    bucket[2]--;
                }
        }
    }
};

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a = 0;
        int m = 0;
        int b = nums.size()-1;
        while (m<=b){
            if (nums[m]==0 ){
                swap(nums[a++],nums[m++]);
            }
            else if (nums[m] == 1 ) m++;
            else swap(nums[m],nums[b--]);

        }
    }
};
