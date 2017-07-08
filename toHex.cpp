class Solution {
    const string h = "0123456789abcdef";
public:
    string toHex(int num) {
        if (num==0) return "0";
        string res;
        int count = 0;
        while(num && count++ < 8){
            res = h[num&15]+res;
            num >>= 4;
        }
        return res;
    }
};
