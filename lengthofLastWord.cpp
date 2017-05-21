class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(s.begin(),s.end());
        stringstream ss;
        ss<<s;
        string temp;
        ss>>temp;
        return temp.size();
    }
};
