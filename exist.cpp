class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for (int i = 0 ; i < m;i++){
            for (int j = 0; j < n; j++){
                if (search(board,word,0,i,j)) return true;
            }
        }
        return false;
    }
private:
    int m;
    int n;
    bool search(vector<vector<char>>& board,string word, int k,int x,int y){
        if (k == word.size()) return true;
        if (x < 0 || y < 0 || x >=m || y>=n || board[x][y]!=word[k])return false;
        char tmp = board[x][y];
        board[x][y] = '\0';
        if (search(board,word,k+1,x+1,y)||search(board,word,k+1,x-1,y)||search(board,word,k+1,x,y+1)||search(board,word,k+1,x,y-1)) return true;
        board[x][y] = tmp;
        return false;

    }
};
