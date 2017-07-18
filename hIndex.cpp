class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (!citations.size()) return 0;
        vector<int> res;
        sort(citations.begin(),citations.end(),[](int a,int b){return a > b;});
        for (int i = 1 ; i <=citations.size();i++){
            if (i<=citations[i-1]) res.push_back(i);
        }
        if (!res.size()) return 0;
        return res.back();

    }
};


class Solution {
public:

int hIndex(vector<int>& citations) {
    if(citations.empty())
        return 0;
    int n = citations.size();
    vector<int> hash(n + 1, 0);
    for(int i = 0; i < n; ++i){
        if(citations[i] >= n)
            hash[n]++;
        else
            hash[citations[i]]++;
    }
    int paper = 0;
    for(int i = n; i >= 0; --i){
        paper += hash[i];
        if(paper >= i)
            return i;
    }
}
};
