#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int count =0;
        int j = 0 ;
        cout<<"call function"<<endl;
        for (int i = 0 ; (i < g.size()) && (j < s.size()); ++i){
            while (g[i] > s[j] && j < s.size() ){
                j++;
                cout<<j<<"$$"<<endl;
            }
            // if (j = s.size()) break;
            if (g[i] <= s[j]){
                cout<<"here!"<<endl;
                count++;
                j++;
            }
        }
        return count;
    }


int main(int argc, char const *argv[]){
    vector<int> v1 = {1,1,2,};
    vector<int> v2 = {2,3};
    cout<<findContentChildren(v1,v2)<<endl;
    return 0;
}
