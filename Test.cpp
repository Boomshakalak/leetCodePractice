#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <bitset>
#include <string>
#include <climits>
using namespace std;
string add(string n, string m){
    string res;
    int i=n.size()-1, j=m.size()-1, carry=0;
    while(i>=0 || j>=0){
        int sum=carry+(i>=0 ? (n[i--]-'0') : 0) + (j>=0?  (m[j--]-'0') : 0);
        res.push_back(sum%10+'0');
        carry=sum/10;
    }
    if(carry) res.push_back(carry+'0');
    reverse(res.begin(), res.end());
    return res;
}
int main(int argc, char const *argv[]) {
    string a = "123";
    string b = "535";
    cout<<add(a,b)<<endl;
    return 0;
}
