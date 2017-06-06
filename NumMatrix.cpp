class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        if (matrix.empty()) return;
        int m = matrix.size();
        int n = matrix[0].size();
        res = matrix;
        for (int i = 0 ; i < m; i++){
            int tmp = 0;
            for (int j = 0 ; j < n; j++){
                tmp += matrix[i][j];
                res[i][j] = (i==0?0: res[i-1][j])+tmp;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 && col1) return res[row2][col2]-res[row1-1][col2]-res[row2][col1-1]+res[row1-1][col1-1];
        if (row1) return res[row2][col2]-res[row1-1][col2];
        return res[row2][col2]-res[row2][col1-1];

    }
private:
    vector<vector<int>> res;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
