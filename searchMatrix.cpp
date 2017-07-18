class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        if  (n==0) return false;
        int l = 0 ;
        int r = m ;
        while (l < r){
            int med = (r+l)>>1;
            if (matrix[med][0] <= target) l = med+1;
            else r = med;
        }
        l = l?l-1:0;
        int sl = 0;
        int sr = n;
        while(sl < sr){
            int med = (sl+sr)>>1;
            if (matrix[l][med]== target) return true;
            else if (matrix[l][med] < target) sl = med+1;
            else sr = med;
        }
        return false;
    }
};
