class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res(n,vector<int>(n,0));
    int count = 1;
    int x = 0;
    while(x<n/2){
        for (int i = x ; i < n-x-1; i++){
            res[x][i] = count;
            count++;
        }
        for (int i = x; i < n-x-1;i++){
            res[i][n-x-1] = count;
            count++;
        }
        for (int i = x;i < n-x-1;i++){
            res[n-x-1][n-1-i] = count;
            count++;
        }
        for (int i = x; i < n-x-1; i++){
            res[n-1-i][x] = count;
            count++;
        }
        x++;
    }
    if (n%2 == 1) res[n/2][n/2] = count;
    return res;
}
};
