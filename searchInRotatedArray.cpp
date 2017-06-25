class Solution {
public:
    int search(vector<int>& nums, int target) {
        return nsearch(nums,0,nums.size()-1,target);
    }
    int nsearch(vector<int>& a,int l,int u,int target){
        if (l > u) return -1;
        int m = (l+u)/2;
        if (a[m] == target) return m;
        if (a[l] <= a[m]){
            if (target > a[m]) l = m+1;
            else if (target >= a[l] ) u = m-1;
            else l = m+1;
        }
        else if (target < a[m]) u = m-1;
        else if (target <= a[u]) l = m+1;
        else u = m-1;
        return nsearch(a,l,u,target);
    }
};
