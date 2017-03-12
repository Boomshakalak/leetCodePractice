class Solution {
public:
    bool static strcm(string &a,string &b){
	string temp1= a+b;
	string temp2 =b+a;
	return temp1>temp2;
}
    string largestNumber(vector<int>& nums) {
        vector<string> res;
        for (auto x:nums)res.push_back(to_string(x));
        sort(res.begin(),res.end(),strcm);
        string temp;
        for (auto x:res)temp+=x;
        while(temp[0]=='0'&& temp.size()>1)temp=temp.substr(1);
        return temp;
    }
};