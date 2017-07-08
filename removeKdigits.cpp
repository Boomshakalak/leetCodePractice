class Solution {
public:
    string removeKdigits(string num, int k) {
        string res;
        for (auto x : num){
            while (res.size() && res.back() > x && k){
                res.pop_back();
                k--;
            }
            if (res.size() || x != '0') res.push_back(x);
        }
        while(res.size() && k--)res.pop_back();
        return res.size()?res:"0";
    }
};
