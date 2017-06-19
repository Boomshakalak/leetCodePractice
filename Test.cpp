/* leetcode test code */
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>
#include <climits>
#include <string>
using namespace std;
vector<string> split(const string & str){
    vector<string> res;
    string tmp = "";
    bool flag = true;
    for (int i = 0; i <= str.size();i++){
        if ((str[i] == ' ' || i == str.size()) && tmp.size() && flag){
            res.push_back(tmp);
            tmp.clear();
        }
        else if (str[i] ==' ' && flag) continue;
        else
            {
                if (str[i] == '\"') flag = !flag;
                else tmp+=str[i];

            }
    }
    return res;
}
int main(int argc, char const *argv[])
{
    vector<string> vs;
    string s = "           I     have a \"faux coat\" and I like \" hhh\"";
    vs = split(s);
    cout<<vs.size()<<endl;
    for (auto x:vs){
        cout<<x<<endl;
    }
    return 0;
}
