class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (!n) return 0;
        vector<int> dpmax(n);
        vector<int> dpmin(n);
        dpmax[0] = nums[0];
        dpmin[0] = nums[0];
        for (int i = 1 ; i < n ; i++){
            dpmax[i] = getmax({dpmax[i-1]*nums[i],dpmin[i-1]*nums[i],nums[i]});
            dpmin[i] = getmin({dpmax[i-1]*nums[i],dpmin[i-1]*nums[i],nums[i]});
        }
        int res = getmax(dpmax);
        return res;
    }
    int getmax(vector<int> v){
        int res = INT_MIN;
        for (auto x : v) res = max(res,x);
        return res;
    }
    int getmin(vector<int> v){
        int res = INT_MAX;
        for (auto x : v) res = min(res,x);
        return res;
    }
};

//DP iteration mostly can be modified to get a O(1) space solution, not always intuitive but maybe sometime required in an interview

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (!n) return 0;
        int dpmax = nums[0];
        int dpmin = nums[0];
        int res = nums[0];
        for (int i = 1 ; i < n ; i++){
            int tmp1 = dpmax;
            int tmp2 = dpmin;
            dpmax = max(max(tmp1*nums[i],tmp2*nums[i]),nums[i]);
            dpmin = min(min(tmp1*nums[i],tmp2*nums[i]),nums[i]);
            res = max(res,dpmax);
        }
        return res;
    }

};
