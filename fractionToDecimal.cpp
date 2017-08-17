class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (!numerator) return "0";
        string res;
        if (numerator < 0 ^ denominator < 0) res += '-';
        long numer = labs(numerator);
        long denom = labs(denominator);
        long integral = numer / denom;
        res += to_string(integral);
        long rmd = numer % denom;
        if (!rmd) return res;
        res += '.';
        rmd *= 10;
        unordered_map<long, long> mp;
        while (rmd) {
            long quotient = rmd / denom;
            if (mp.count(rmd)) {
                res.insert(mp[rmd],  "(");
                res += ')';
                break;
            }
            mp[rmd] = res.size();
            res += (quotient);
            rmd = (rmd % denom) * 10;
        }
        return res;
    }
};
