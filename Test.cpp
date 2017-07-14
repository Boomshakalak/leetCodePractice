#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <bitset>
#include <string>
#include <climits>
#include <sstream>
#include <unordered_map>
#include <fstream>
#include <unordered_set>
using namespace std;
string readFileIntoString(const char * filename)  {
    ifstream ifile(filename);
    string s;
    char ch;
    while(ifile.get(ch))
    s.push_back(ch);
    return s;
}
vector<string> split(string& str){
    int i = 0;
    int j = 0;
    vector<string> res;
    while (j < str.size()){
        j++;
        if (j == str.size() || str[j]== ','){
            res.push_back(str.substr(i,j-i));
            i = j+1;
        }
    }
    return res;
}
int main(int argc, char const *argv[]) {
    const char* f1 = "cmd.txt";
    const char* f2 = "parab.txt";
    const char* f3 = "res.txt";
    const char* f4 = "ans.txt";
    string cmd = readFileIntoString(f1);
    string para = readFileIntoString(f2);
    string res = readFileIntoString(f3);
    string ans = readFileIntoString(f4);
    auto cmd1 = split(cmd);
    auto para1 = split(para);
    auto res1 = split(res);
    auto ans1 = split(ans);
    cout<<"ans1.size::" <<ans1.size()<<endl;
    cout<<"para.size::"<<para1.size()<<endl;
    for (int i = 0 ; i < ans1.size();i++){
        if (para1[i] == "forefin") cout<<"we find ten"<<endl;
        if (ans1[i] != res1[i]){
            cout<<i<<endl;
            cout<<"command:"<<cmd1[i]<<endl;
            cout<<"para:"<<para1[i]<<endl;
            cout<<"res:"<<res1[i]<<endl;
            cout<<"ans:"<<ans1[i]<<endl;
        }
    }
    return 0;

}
