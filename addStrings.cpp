class Solution {
public:
    string addStrings(string num1, string num2) {
        if (num1.size() < num2.size()) return addStrings(num2,num1);
        string tmp1 = num1;
        string tmp2 = num2;
        reverse(tmp1.begin(),tmp1.end());
        reverse(tmp2.begin(),tmp2.end());
        int c = 0;
        string res;
        for (int i = 0 ; i < tmp1.size() || c ;i++){
            if (i < tmp2.size())
            {
                int a = tmp1[i]-'0'+tmp2[i]-'0'+c;
                c = a/10;
                res.push_back(a%10+'0');
            }
            else if (i < tmp1.size()){
                int a = tmp1[i]-'0'+c;
                c = a/10;
                res.push_back(a%10+'0');
            }
            else
                {
                res.push_back(c+'0');
                break;
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
