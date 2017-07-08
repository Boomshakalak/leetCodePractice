#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <bitset>
#include <climits>
using namespace std;
int c(int m, int n){
    int k = m;
    long long n1 = 1;
    int count =n;
    while(count--){
        n1 = n1*k;
        k--;
    }
    long long n2 = 1;
    int i = 1;
    while(i <n){
        i++;
        n2 = n2*i;
    }
    if (!n2) return 1;
    return (n1/n2);
}

int main(int argc, char const *argv[]) {
    int k = INT_MAX;
    cout<<bitset<64>(k).count()<<endl;
    return 0;
}
