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
#include <unordered_set>
using namespace std;

string removeDuplicateLetters(string s) {
    int count[26] ={0};
    for (auto x : s)count[x-'a']++;
    string res;
    unordered_set<char> occur;
    for (auto t : s){
        if (!occur.count(t)){
            while (res.size() && count[res.back()-'a']>1 && res.back() > t){
                count[res.back()-'a']--;
                occur.erase(res.back());
                res.pop_back();
            }
            cout<<"appending:"<<t<<endl;
            res.push_back(t);
            cout<<res<<endl;
            occur.insert(t);
        }
        else count[t-'a']--;
    }
    return res;
}
int main(int argc, char const *argv[]) {
    string s = "abacb";
    cout<<removeDuplicateLetters(s)<<endl;
    return 0;

}
