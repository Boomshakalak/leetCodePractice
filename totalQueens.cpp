// This one is similiar to place N queens but only need to know how many solutions exist.

class Solution {
public:
    int totalNQueens(int n) {
        vector<int> tmp;
        int count = 0;
        getPos(tmp,n,count);
        return count;
    }
    void getPos(vector<int> &tmp,int n,int &count){
        if (tmp.size() == n)count++;
        else
            {
                for (int i = 0 ; i < n ; i++){
                    if (valid(tmp,i)){
                        tmp.push_back(i);
                        getPos(tmp,n,count);
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
};
