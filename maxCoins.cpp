class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int s = nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> rangeRes(n,vector<int>(n,0));
        for (int len =1 ; len <= s ; len++ ){
            for (int start = 1; start + len -1 <= s; start++){
                int end = start + len -1 ;
                int curBest = 0 ;
                for (int f = start; f <= end; f++){
                    int coin = rangeRes[start][f-1]+rangeRes[f+1][end]+nums[start-1]*nums[f]*nums[end+1];
                    curBest = max(curBest, coin);
                }
                rangeRes[start][end] = curBest;
            }
        }
        return rangeRes[1][s];
    }
};
