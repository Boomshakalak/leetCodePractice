class Solution {
public:
    int longestSubstring(string s, int k) {
        return longest_recur(s,k,0,s.size());
    }
    int longest_recur(string &s, int k, int start,int end){
        int count[26]={0};
        for (int i = start; i < end; i++)count[s[i]-'a']++;
        int maxlen = 0;
        for (int i = start; i < end; ){
            while (count[s[i]-'a'] < k)i++;
            if (i == end) break;
            int j = i;
            for (; j < end;){
                if (count[s[j] - 'a'] >= k)j++;
                else break;
            }
            if (i == start && j == end) return end-start;
            maxlen = max(maxlen,longest_recur(s,k,i,j));
            i=j;
        }
        return maxlen;
    }
};
