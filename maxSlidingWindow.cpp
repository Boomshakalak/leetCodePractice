class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> res;
        if (!nums.size()) return res;
        multiset<int,greater<int>> ms;
        for (int i = 0 ; i < k ; i++){
            q.push_back(nums[i]);
            ms.insert(nums[i]);
        }
        res.push_back(*ms.begin());
        for (int i = k ; i < nums.size();i++){
            int tmp = q.front();
            q.pop_front();
            q.push_back(nums[i]);
            ms.erase(ms.find(tmp));
            ms.insert(nums[i]);
            res.push_back(*ms.begin());
        }
        return res;
    }

};
