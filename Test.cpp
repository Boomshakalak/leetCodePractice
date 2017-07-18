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
#include <map>
using namespace std;
bool b_search(vector<int>& v, int target){
    int l  = 0 ;
    int h = v.size();
    while(l<= h){
        int m = (l+h)/2;
        if (v[m] == target) return true;
        v[m] < target ? l = m+1 : h = m;
    }
    return false;
}
int main(int argc, char const *argv[]) {
    vector<int> v = {1,2,3,45,52,67,76,81,999,1003};
    if (b_search(v,45)) cout<<"YES"<<endl;
    else cout<<"No"<<endl;
    return 0;

}
