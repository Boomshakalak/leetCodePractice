class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        if  (n==0) return false;
        int l = 0 ;
        int r = m-1 ;
        while (l <= r){
            int med = (r+l)/2;
            if (matrix[med][0] <= target) l = med+1;
            else r = med-1;
        }
        int nl = (l==0?0:(l-1));
        int sl = 0;
        int sr = n-1;
        while(sl <= sr){
            int med = (sl+sr)/2;
            if (matrix[nl][med]== target) return true;
            else if (matrix[nl][med] < target) sl = med+1;
            else sr = med-1;
        }
        return false;
    }
};
