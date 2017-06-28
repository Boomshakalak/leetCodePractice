/* leetcode test code */
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>
#include <climits>
#include <string>
using namespace std;
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> temp(k,0);
        int i = 0 ;
        while (i >= 0){
            temp[i]++;
            if (temp[i] > n)--i;
            else if (i == k-1) res.push_back(temp);
            else {
                ++i;
                temp[i]=temp[i-1];
            }

        }
        return res;
    }
};
int main(int argc, char const *argv[])
{
    Solution p;
    vector<vector<int>> res = p.combine(5,3);
    for (auto x : res){
        for (auto t : x)cout<<t<<" ";
        cout<<endl;
    }
    return 0;
}
