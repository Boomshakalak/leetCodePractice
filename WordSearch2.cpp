class node{
public:
    vector<node*> branch;
    bool end;
    node(){
        branch = vector<node*>(26,NULL);
        end = false;
    }

};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();
        snapshot = board;
        root = new node();
        vector<string> dic;
        string tmp;
        unordered_set<string> us;
        vector<string> res;
        for (auto x : words)insert(x);
        for (int i = 0 ; i < m ; i++){
            for (int j  = 0 ; j < n; j++){
                tmp.clear();
                board = snapshot;
                searchBoard(us,tmp,board,root,i,j);
            }
        }
        for (auto x : us)res.push_back(x);
        return res;
    }
    void insert(string word) {
        int i = 0 ;
        node* cur = root;
        while (i < word.size()){
            int idx = word[i++]-'a';

            if (cur->branch[idx]){
                cur = cur->branch[idx];
            }
            else {
                cur->branch[idx] = new node();
                cur = cur->branch[idx];
            }
            if ( i == word.size()) cur->end = true;
        }
    }
    int m;
    int n;
    node* root;
    vector<vector<char>> snapshot;
    void searchBoard(unordered_set<string>& res, string& tmp,vector<vector<char>>& board,node* cur,int i, int j){

        if (board[i][j] == '0') return;
        char ch = board[i][j];
        int index = ch - 'a';
        if (!cur->branch[index]) return;
        tmp.push_back(ch);
        if (cur->branch[index]->end)res.insert(tmp);
        tmp.pop_back();
        vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
        for (auto x : dir){
            int nx = i + x.first;
            int ny = j + x.second;
            if (nx < m && nx >=0 && ny < n && ny >=0 ){
                tmp.push_back(ch);
                board[i][j] = '0';
                searchBoard(res,tmp,board,cur->branch[index],nx,ny);
                board[i][j] = ch;
                tmp.pop_back();
            }
        }
    }
};
