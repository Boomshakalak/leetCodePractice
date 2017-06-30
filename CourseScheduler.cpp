// The intuitive way but a more common way si to detect indegee of the graph nodes
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if (!prerequisites.size()) return true;
        vector<bool> alreadyDone(numCourses,true);
        for(auto x : prerequisites) alreadyDone[x.first] = false;
        unordered_map<int,vector<int>> um;
        buildGraph(um,prerequisites);
        while(xtend(alreadyDone,um));
        for (auto x: alreadyDone){
            if (x == false) return false;
        }
        return true;
    }
    void buildGraph(unordered_map<int,vector<int>>& um,vector<pair<int, int>>& prerequisites){
        for (auto x:prerequisites){
            um[x.first].push_back(x.second);
        }
    }
    bool canlearn(pair<int,vector<int>> t,vector<bool>& alreadyDone){
        for (auto x : t.second){
            if (!alreadyDone[x]) return false;
        }
        return true;
    }
    bool xtend(vector<bool>& alreadyDone, unordered_map<int,vector<int>>& um){
        bool cont = false;
        for (auto x : um){
            if (!alreadyDone[x.first] && canlearn(x,alreadyDone)){
                alreadyDone[x.first] = true;
                cont = true;
            }
        }
        return cont;
    }

};
