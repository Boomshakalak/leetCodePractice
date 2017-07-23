class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string ans;
        for (auto x : d){
            int p1 = 0;
            int p2 = 0;
            for (;p1 < s.size(); p1++)p2 += s[p1] ==x[p2];
            if (p2 == x.size() && (x.size() > ans.size() ||(x.size() == ans.size() && x < ans)))ans = x;
        }
        return ans;
    }
};
