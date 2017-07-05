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
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (!m) return;
        int n = board[0].size();
        unordered_set<pair<int,int>,myHash> upii;
        getFreeO(upii,board);
        for (int i = 1; i< m ; i++){
            for (int j = 1 ; j < n ; j++){
                if (board[i][j] =='O' && !upii.count(make_pair(i,j)))board[i][j] = 'X';
            }
        }
    }
    void getFreeO(unordered_set<pair<int,int>,myHash>& upii,vector<vector<char>>& board){
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m ;i++){
            for (int j = 0 ; j < n ; j++){
                if (i*j == 0 || i==m-1 || j == n-1){
                    if (board[i][j]=='O' && !upii.count(make_pair(i,j))){
                        queue<pair<int,int>> q;
                        q.push(make_pair(i,j));
                        upii.insert(make_pair(i,j));
                        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
                        while(!q.empty()){
                            auto t = q.front();
                            q.pop();
                            for (auto x:dir){
                                int nx = t.first + x.first;
                                int ny = t.second + x.second;
                                if (nx>=0 && nx < m && ny >=0 && ny < n && !upii.count(make_pair(nx,ny))){
                                    if (board[nx][ny] =='O'){
                                        q.push(make_pair(nx,ny));
                                        upii.insert(make_pair(nx,ny));
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

};
