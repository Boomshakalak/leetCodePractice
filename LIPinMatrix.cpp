class Solution {
public:
    struct myHash
    {
        size_t operator()(pair<int, int> val) const
        {
            string s = to_string(val.first)+","+to_string(val.second);
            hash<string> hf;
            return hf(s);
        }
    };
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (!matrix.size()) return 0;
		vector<vector<unordered_set<pair<int,int>,myHash>>> graph = getGraph(matrix);
        vector<vector<int>> degree = indegree(graph);
        return getLength(degree,graph);
    }
    vector<vector<unordered_set<pair<int,int>,myHash>>> getGraph(vector<vector<int>>& matrix){
        int m =matrix.size();
        int n = matrix[0].size();
        vector<unordered_set<pair<int,int>,myHash>> k(n);
        vector<vector<unordered_set<pair<int,int>,myHash>>> res(m,k);
        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        for (int i = 0 ; i < m ; i++){
            for (int j = 0 ; j < n; j++){
                for (auto x : dir){
                    int nx = i+x.first;
                    int ny = j+x.second;
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n){
                        if (matrix[i][j] < matrix[nx][ny]){
                            res[i][j].insert(make_pair(nx,ny));
                        }
                    }
                }
            }
        }
        return res;
    }
    vector<vector<int>> indegree(vector<vector<unordered_set<pair<int,int>,myHash>>>& graph){
        int m = graph.size();
        int n = graph[0].size();
        vector<int> k(n,0);
        vector<vector<int>> res(m,k);
        for (auto x : res) x = k;
        for (int i = 0; i < m ; i++){
            for (int j = 0; j < n; j++){
                for (auto x : graph[i][j]){
                    res[x.first][x.second]++;
                }
            }
        }
        return res;
    }
    int getLength(vector<vector<int>>& indegree,vector<vector<unordered_set<pair<int,int>,myHash>>>& graph){
        int maxlen = 1;
        int m = graph.size();
        int n = graph[0].size();
        vector<int> k(n,1);
        vector<vector<int>> res(m,k);
        while (1){
            int i;
            int j;
            bool find = false;
            for (i = 0; i < m ; i++){
                for (j = 0; j < n &&!find ; j++){
                    if (!indegree[i][j]) {
                        find = true;
                        break;
                    }
                }
                if (find) break;
            }
            if ( i == m && j == n) return maxlen;
            indegree[i][j] = -1;
            for (auto x : graph[i][j]){
                 res[x.first][x.second] = max(res[x.first][x.second],res[i][j]+1);
                 maxlen = max(maxlen,res[x.first][x.second]);
                 indegree[x.first][x.second]--;
            }
        }
        return maxlen;
    }

};
