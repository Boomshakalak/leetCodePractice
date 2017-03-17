#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;



int main(int argc, char const *argv[]){
    int n;
    string res = "1";
    std::cin >> n;
    while (--n) {
        string cur = "";
        for (int i = 0; i < res.size(); i++) {
            int count = 1;
             while ((i + 1 < res.size()) && (res[i] == res[i + 1])){
                count++;
                i++;
            }
            cur += to_string(count) + res[i];
        }
        res = cur;
    }
    cout<<s<<endl;
    return 0;
}
