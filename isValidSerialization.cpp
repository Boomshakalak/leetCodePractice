class Solution {
public:
    bool isValidSerialization(string preorder) {
        int nodeCnt=0,nullCnt=0;
        vector<string> v=splitStr(preorder,',');
        for(int i = 0; i<v.size(); i++){
            if(v[i]=="#") ++nullCnt;
            else ++nodeCnt;
            if(nullCnt>=nodeCnt+1 && i!=v.size()-1) return false;
        }
        return nullCnt==nodeCnt+1;
    }

    vector<string> splitStr(string str, char delimiter){
    	vector<string> r;
    	int i ;
        int j ;
        for (i = 0,j = 0;j < str.size();){
            j++;
            if (j == str.size() || str[j] == ','){
                r.push_back(str.substr(i,j-i));
                i = j+1;
            }
        }
    	return r;
    }
};
