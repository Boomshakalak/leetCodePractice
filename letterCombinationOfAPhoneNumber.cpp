class Solution {
public:
    string dic[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> vr;
    vector<string> letterCombinations(string digits) {
        string temp="";
        gen(temp,digits,digits.size());
        return vr;
    }
    void gen(string temp,string digits, int k){
        if (!digits.size()) return;
        string cbn= dic[digits[0]-'0'];
        for (int i = 0 ; i < cbn.size();i++){
            temp+=dic[digits[0]-'0'][i];
            gen(temp,digits.substr(1),k);
            if (temp.size()==k) vr.push_back(temp);            
            temp.pop_back();
        }
    }
};