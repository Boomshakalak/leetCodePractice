//This is a smart solution that for a sliding window, the lenght is increasing by iteration while i and j are not neccearily the true index of the result answer
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> m(128, 0);
        int count = 0, begin = 0, end = 0, d = 0;
        while(end < s.size())
        {
            m[s[end]]++;
            if (m[s[end]] > count) count = m[s[end]];
            end++;
            if (end - begin - count > k)
            {
                m[s[begin]]--;
                begin++;
            }
        }
        d = end - begin;
        return d;
    }
};
int characterReplacement(string s, int k) {
    int i = 0, j = 0, ctr[91] = {};
    while (j < s.size()) {
        ctr[s[j++]]++;
        if (j-i - *max_element(ctr+65, ctr+91) > k)
            ctr[s[i++]]--;
    }
    return j - i;
}
