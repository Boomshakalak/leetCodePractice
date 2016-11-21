class Solution {
public:
    long long myAtoi(string str) {
        if (!str.size()) return 0;
        long long res = 0;
        int start = 0;
        int flag = 1;
        stringstream ss;
        ss<<str;
        ss>>str;
        if (str[0]=='-' || str[0] == '+') {
        	start = start+1;
        	flag = str[0]=='+'?1:-1;
        }

        for (int i = start;i<str.size();i++){
        	if (str[i]<'0' || str[i]>'9') break;
        	res=res*10+int(str[i]-'0');
        	if (res > INT_MAX || res < INT_MIN) break;
        }
        res = res*flag;
        if (res > INT_MAX) return INT_MAX;
        if (res < INT_MIN) return INT_MIN;
        return res;
    }
};