class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int res = 0;
        int m = board.size();
        if (!m) return 0;
        int n = board[0].size();
        for (int i = 0 ; i < m;i++ ){
            for (int j = 0 ; j < n;){
                if (board[i][j] == 'X'){
                    if (i != m-1){
                        if (board[i+1][j]=='.')res++;
                    }
                    else
                        res++;
                    j = findEnd(i,j,board);
                }
                j++;
            }
        }
        return res;
    }
    int findEnd(int i,int j, vector<vector<char>>& board){
        int n = board[0].size();
        int m;
        for (m = j+1; m <n; m++){
            if (board[i][m] =='.') return m-1;
        }
        return m;
    }
};
