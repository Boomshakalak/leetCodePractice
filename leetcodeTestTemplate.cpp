/* leetcode test code */
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>
#include <climits>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int cur = 0;
        int p1 = 0;
        int p2 = height.size()-1;
        for (; p1 < p2; ){
            cur = min(height[p1],height[p2])*(p2-p1);
            if (res<cur) res = cur;
            if (height[p1]<height[p2]) p1++;
            else p2--;
        }
        return res;
    }
};
int main(int argc, char const *argv[])
{
	Solution p;
	vector<int> vi={5,7,9,3,12,77,36};
	int k= p.maxArea(vi);
    cout<<k<<endl;
	return 0;
}