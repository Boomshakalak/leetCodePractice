class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0,j=s.size()-1;
        while(i<=j){
            if (!isalnum(s[i])){i++;continue;}
            if (!isalnum(s[j])){j--;continue;}
            if (toupper(s[i++]) != toupper(s[j--]))return false;
        }
        return true;
    }
};
