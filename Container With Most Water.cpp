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
};