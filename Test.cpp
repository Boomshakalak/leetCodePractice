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

int get(int n){
    if (n < 7) return n;
    vector<int> dp(n+1,0);
    for (int i = 0 ; i < 7 ; i++){
        dp[i] = i ;
    }
    for (int i = 7 ; i <= n ; i++){
        for (int j = 7 ; j >=3; j-- ){
            dp[i] = max(dp[i-j]*(j-1),dp[i]);
        }
    }
    return dp[n];
}
int main(int argc, char const *argv[]) {
    int x;
    while(cin>>x){
        cout<<get(x)<<endl;
    }
    return 0;
}
