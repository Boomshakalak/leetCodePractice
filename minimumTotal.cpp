class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (!triangle.size()) return 0;
        vector<vector<int>> res(triangle);
        int m = triangle.size()-1;
        for (int i = m ; i >=0;--i){
            if (i == m){
                for (int j = 0 ; j < triangle[m].size();j++) res[i][j]=triangle[i][j];
            }
            else
               {
                   for (int j = 0 ; j < triangle[i].size();j++){
                        res[i][j] = min(res[i+1][j],res[i+1][j+1])+triangle[i][j];
                   }

               }
        }
        return res[0][0];

    }
};
