class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_map<int,int> um;
        for (int i : candies)um[i]++;
        int n = um.size();
        int m = candies.size()/2;
        return min(m,n);
    }
};
