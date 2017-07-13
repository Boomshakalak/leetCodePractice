#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <bitset>
#include <string>
#include <climits>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {

public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        auto cmp = [](const vector<string>& a,const vector<string>& b){
            string tmp1,tmp2;
            for (string x : a)tmp1 = tmp1+x;
            for (string x : b)tmp2 = tmp2+x;
            int l1 = tmp1.size();
            int l2 = tmp2.size();
            if (l1 != l2) return l1 > l2;
            return tmp1 < tmp2;
        };
        unordered_map<string,unordered_set<string>> graph =getGraph(tickets);
        vector<vector<string>> res;
        vector<string> tmp;
        tmp.push_back("JFK");
        dfs(res,tmp,graph);
        sort(res.begin(),res.end(),cmp);
        for (auto x :res){
            for (auto t : x)cout<<"t"<<"-->";
            cout<<endl;
        }
        return res[0];
    }
    unordered_map<string,unordered_set<string>> getGraph(vector<pair<string,string>>& tickets){
        unordered_map<string,unordered_set<string>> graph;
        for (auto x : tickets){
            graph[x.first].insert(x.second);
        }
        return graph;
    }
    void dfs(vector<vector<string>>& res, vector<string>& tmp, unordered_map<string,unordered_set<string>>& graph){
        string cur = tmp.back();
        if (graph[cur].empty()) res.push_back(tmp);
        else for (auto x : graph[tmp.back()]){
            graph[cur].erase(x);
            tmp.push_back(x);
            dfs(res,tmp,graph);
            tmp.pop_back();
            graph[cur].insert(x);
        }
    }

};
int main(int argc, char const *argv[]) {
    vector<pair<string,string>> s = {{"JFK","KUL"},{"JFK","NRT"},{"NRT","JFK"}};
    Solution p;
    p.findItinerary(s);
    return 0;

}
