//using indegree to make it classical!!
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> res;
        vector<unordered_set<int>> graph = getGraph(numCourses,prerequisites);
        vector<int> indegree = get_indegree(numCourses,graph);
        for (int i = 0 ; i < numCourses;i++){
            int j = 0;
            for (;j < numCourses;j++){
                if (!indegree[j])break;
            }
            if (j == numCourses) return vector<int>();
            indegree[j]=-1;
            res.push_back(j);
            for (auto t:graph[j]){
                indegree[t]--;
            }
        }
        return res;
    }
    vector<unordered_set<int>> getGraph(int numCourses, vector<pair<int,int>>& prerequisites){
        vector<unordered_set<int>> vu(numCourses);
        for (auto x: prerequisites){
            vu[x.second].insert(x.first);
        }
        return vu;
    }
    vector<int> get_indegree(int numCourses, vector<unordered_set<int>>& vu){
        vector<int> indegree(numCourses,0);
        for (auto x:vu){
            for (auto t:x){
                indegree[t]++;
            }
        }
        return indegree;
    }
};
