class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double l = -10000;
        double h = 10000;
        while(h-l > 0.00001){
            double m = (h+l)/2;
            if (ok(m,nums,k))l =m;
            else h = m;
        }
        return l;
    }
    bool ok(double cur,vector<int>&nums, int k){
        int n = nums.size();
        vector<double> psum(n+1,0);
        double min1 = INT_MAX;
        for (int i = 0 ; i < n ; i++){
            psum[i+1] = psum[i]+nums[i]-cur;
            if (i >= k -1){
                min1 = min(min1,psum[i-k+1]);
                if (psum[i+1]-min1>=0) return true;
        }
        }


        return false;
    }
};
