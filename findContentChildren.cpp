    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int count =0;
        int j = 0 ;
        for (int i = 0 ; i < g.size() && j < s.size(); ++i){
            while (g[i] > s[j] && j < s.size() ){
                j++;
            }
            if (j = s.size()) break;
            if (g[i] <= s[j]){
                count++;
                j++;
            }
        }
        return count;
    }