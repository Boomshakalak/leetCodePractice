class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0;
        int start = -1;
        vector<int> bucket(256,-1);
        for (int i = 0 ; i < s.size();i++){
            if (bucket[s[i]]> start) start = bucket[s[i]];
            bucket[s[i]] = i;
            maxlen = max(maxlen,i-start);

        }
        return maxlen;
    }

};
