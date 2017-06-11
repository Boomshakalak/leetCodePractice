class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int c = 0;
        while (a.size() || b.size() || c){
            int m = (a.size()?a[a.size()-1]:'0') - '0';
            int n = (b.size()?b[b.size()-1]:'0') - '0';
            if (a.size())a.pop_back();
            if (b.size())b.pop_back();
            int k = m+n+c;
            c = k/2;
            k = k%2;
            res = char(k+'0')+res;
        }
        return res;
    }
};
