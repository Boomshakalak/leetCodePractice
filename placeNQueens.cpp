class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> tmp;
        getPos(res,tmp,n);
        return res;
    }
    void getPos(vector<vector<string>> & res, vector<int> &tmp,int n){
        if (tmp.size() == n)generate(res,tmp,n);
        else
            {
                for (int i = 0 ; i < n ; i++){
                    if (valid(tmp,i)){
                        tmp.push_back(i);
                        getPos(res,tmp,n);
                        tmp.pop_back();
                }
            }
            }
    }
    bool valid(vector<int> &vi,int k){
        int cur = vi.size();
        for (int i = 0 ; i < vi.size();i++){
            if (k == vi[i] ||(abs(cur-i) == abs(k-vi[i])))return false;
        }
        return true;
    }
    void generate(vector<vector<string>> &res,vector<int> vi, int n){
        vector<string> tmp;
        for (int x : vi){
            string str(n,'.');
            str[x]='Q';
            tmp.push_back(str);
        }
        res.push_back(tmp);
    }
};
