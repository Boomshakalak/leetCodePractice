class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int cur = 0;
        while(cur < data.size()){
            if (!check(data,cur)) return false;
        }
        return true;
    }
    int getLen(vector<int>& data,int cur){
        bitset<8> b(data[cur]);
        int count = 0;
        for (int i = 7 ; i >=0;i--){
            if (b[i]) count++;
            else break;
        }
        return count;
    }
    bool check(vector<int> data, int& cur){
        int l = getLen(data,cur);
        if (l>4) return false;
        if (l == 1) return false;
        if (l == 0)l = 1;
        if (cur+l >data.size()) return false;
        for (int i =cur+1; i <cur+l;i++){
            bitset<8> tmp(data[i]);
            if (tmp[7] && !tmp[6]) continue;
            else return false;
        }
        cur = cur+l;
        return true;
    }
};
