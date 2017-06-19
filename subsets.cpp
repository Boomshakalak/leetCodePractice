class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> tmp;
        vector<vector<int>> res;
        getsub(tmp,res,0,nums);
        return res;
    }
    void getsub(vector<int> &sub,vector<vector<int>> & res, int start,vector<int> & nums){
        res.push_back(sub);
        for (int i = start; i < nums.size();i++){
            sub.push_back(nums[i]);
            getsub(sub,res,i+1,nums);
            sub.pop_back();
        }
    }
};

//Iterative method

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> subs(1, vector<int>());
        for (int i = 0; i < nums.size(); i++) {
            int n = subs.size();
            for (int j = 0; j < n; j++) {
                subs.push_back(subs[j]);
                subs.back().push_back(nums[i]);
            }
        }
        return subs;
    }
};

// bit mask method

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int num_subset = 1<<nums.size();
        vector<vector<int> > res(num_subset, vector<int>());
        for (int i = 0; i < nums.size(); i++)
            for (int j = 0; j < num_subset; j++)
                if ((j >> i) & 1)
                    res[j].push_back(nums[i]);
        return res;
    }
};
