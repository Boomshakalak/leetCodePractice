
class Solution {
private:
    bool doable (const vector<int>& nums, int cuts, long long max) {
        int acc = 0;
        for (int  num : nums) {
            if (acc + num <= max) acc += num;
            else {
                --cuts;
                acc = num;
                if (cuts < 0) return false;
            }
        }
        return true;
    }

public:
    int splitArray(vector<int>& nums, int m) {
        long long left = 0, right = 0;
        for (int num : nums) {
            left = max(left, (long long)num);
            right += num;
        }

        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (doable(nums, m - 1, mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};


class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        //dp[i][k] means max sum of k parts of elements 0..i
        vector<vector<long>> dp(n, vector<long>(m+1, INT_MAX));
        //sum array is used to calculate range sum of i..j
        vector<long> sum(n, 0);
        for (int i = 0; i < n; i++) {
            sum[i] = i == 0 ?nums[0] :(sum[i-1] + nums[i]);
        }
        // build dp from 0 to n-1 emelents
        for (int i = 0; i < nums.size(); i++) {
            //elements from 0 to indexi can be divided to i+1 parts mostly;
            int maxDivide = min(m, i+1);
            //for each dividing choice
            for (int k = 1; k <= maxDivide; k++) {
                if (k == 1) {
                    dp[i][k] = sum[i];
                    continue;
                }
                //divide 0..i to k parts, so i can be with i-1; i-1, i-2...; i-1, i-2..k-1;
                for (int j = i; j >= k-1; j--) {//0..k-2 can be divided to mostly k-1 parts
                    long partsum = sum[i] - sum[j] + nums[j];
                    if (partsum > dp[i][k]) break; //early termination
                    dp[i][k] = min(dp[i][k], max(partsum, dp[j-1][k-1]));
                }
            }
        }
        return dp[n-1][m];
    }
};
