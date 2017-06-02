#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <unordered_set>
using namespace std;
int main(int argc, char const *argv[]){
    unordered_set<int> us;
    us.insert(1);
    us.insert(1);
    for (auto x: us)cout<<x<<endl;
    return 0;
}
