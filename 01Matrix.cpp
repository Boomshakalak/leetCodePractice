class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> res(m,vector<int>(n,INT_MAX));
        for (int i = 0 ; i < m; ++i){
            for (int j = 0 ; j < n ; ++j){
                if (matrix[i][j] == 0){
                    res[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
        while(!q.empty()){
            auto s = q.front();
            q.pop();
            int candidate = res[s.first][s.second]+1;
            for (auto x:dir){
                int nx = s.first+x[0];
                int ny = s.second+x[1];
                if (nx>=0 && ny >=0 && nx < m && ny < n ){
                    if (candidate < res[nx][ny]) res[nx][ny] = candidate,q.push({nx,ny});
                }
            }
        }
        return res;
    }
};
