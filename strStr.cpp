class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.size() < needle.size()) return -1;

        int len = needle.size();
        for (int i = 0; i < haystack.size()-len+1;i++){
            if (isSame(haystack,i,needle)) return i;
        }
        return -1;
    }
    bool isSame(string & haystack, int k, string & needle){
        for(int i = 0 ; i < needle.size();i++){
            if (haystack[k+i]!= needle[i]) return false;
        }
        return true;
    }
};
