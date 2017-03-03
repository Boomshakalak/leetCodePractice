class Solution {
public:
string decimal[4]={""," Thousand"," Million"," Billion"};
string digit[10]={"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
string digit2[10]= {"Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
string digit3[10]={"Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
string trans(string threedigit_s){
	int len = threedigit_s.size();
	if (len == 0 ) return "";
	    if (threedigit_s[0] == '0') return trans(threedigit_s.substr(1,len-1));
	if (len == 1) return digit[threedigit_s[0]-'0'];
	if (len == 2) {
		if (threedigit_s[0]=='1') return digit2[threedigit_s[1]-'0'];
		if ((threedigit_s[1]-'0')) return digit3[threedigit_s[0]-'0'-1]+" "+digit[threedigit_s[1]-'0'];
		return digit3[threedigit_s[0]-'0'-1];
	}
	else if ((threedigit_s.substr(1,2) == "00")) return digit[threedigit_s[0]-'0']+" Hundred";
	
	return digit[threedigit_s[0]-'0']+" Hundred "+ trans(threedigit_s.substr(1,2));
}
    string numberToWords(int num) {
        if (num==0) return "Zero";
        string k = to_string(num);
        string s;
        vector<string> res;
        for (int i = k.size()-1; i >=0; i-=3){
            res.push_back(k.substr(i>2?i-2:0,i>2?3:i+1));
        }
        for(int i = res.size()-1;i>=0;i--){
            string temp = trans(res[i]);
            if (temp!="")	s=s+trans(res[i])+decimal[i];
            else 	s=s+trans(res[i]);
        	if (i && (s[s.size()-1]!=' '))s+=" ";
        }
        while(s[s.size()-1]==' ') s=s.substr(0,s.size()-1);
        return s;
    }
};