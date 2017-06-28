class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int x = click[0];
        int y = click[1];
        update(board,x,y);
        return board;
    }
    void update(vector<vector<char>>& board, int x, int y){
        if (board[x][y] == 'M'){
            board[x][y] = 'X';
            return;
        }
        int count = 0;
        vector<vector<int>> dir = {{-1,-1},{-1,0},{-1,1},{0,1},{0,-1},{1,-1},{1,0},{1,1}};
        for (auto t: dir){
            int nx = x+t[0];
            int ny = y+t[1];
            if (nx>=0 && nx < board.size() && ny >=0 && ny < board[0].size()){
                if (board[nx][ny] == 'M')count++;
            }
        }
        if (count == 0){
            board[x][y] = 'B';
            for (auto t: dir){
            int nx = x+t[0];
            int ny = y+t[1];
            if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size()){
                if (board[nx][ny] == 'E')update(board,nx,ny);
            }
        }
    }
        else
            board[x][y] = '0'+count;
    }

};
