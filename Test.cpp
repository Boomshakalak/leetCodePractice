#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <stdlib.h>
using namespace std;
struct Interval {
    int s;
    int t;
    Interval():s(0),t(0){}
    Interval(int a, int b):s(a),t(b){}
};
int main(int argc, char const *argv[]){
    vector<Interval> inteV;
    for (size_t i = 0; i < 10; i++) {
        inteV.push_back(Interval(rand(),rand()));
    }
    sort(inteV.begin(),inteV.end(),[](const Interval &a,const Interval &b){return a.s > b.s;});
    for (auto x: inteV)
    cout<<x.s<<" "<<x.t<<endl;
    return 0;
}
