class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2) return s;
        int maxlen = 1,maxleft = 0,left,right;
        for (int start = 0;start < s.size()-maxlen/2;){
            left = right = start;
            while((right < s.size()-1) && s[right] == s[right+1])right++;
            start = right+1;
            while(left > 0 && s[left-1] == s[right+1]){
                left--;
                right++;
            }
            int nl = right - left + 1;
            if (nl > maxlen){
                maxlen = nl;
                maxleft = left;
            }
        }
        return s.substr(maxleft,maxlen);
    }
};
