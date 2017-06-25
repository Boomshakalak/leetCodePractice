#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int makechange(int n,int denom){
    int next = 0;
    switch (denom) {
        case 25:next = 10;break;
        case 10:next = 5;break;
        case 5: next = 1; break;
        case 1 :return 1;
    }
    int ways = 0;
    for (int i = 0 ; i*denom <= n; i++){
        ways += makechange(n-i*denom,next);
    }
    return ways;
}

int main(int argc, char const *argv[]){
    cout<<makechange(5,25)<<endl;
    return 0;
}
