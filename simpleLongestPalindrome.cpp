class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> m(256,0);
        for (auto x : s)m[x]++;
        int res = 0;
        for (auto t : m){
            res+= t%2?(res%2?t-1:t):t;
        }
        return res;
    }
};
