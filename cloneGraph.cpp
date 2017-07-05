/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return node;
        if (map.count(node)) return map[node];
        UndirectedGraphNode* cnode =  new UndirectedGraphNode(node->label);
        map[node] = cnode;
        for (auto neigh : node->neighbors){
            cnode->neighbors.push_back(cloneGraph(neigh));
        }
        return cnode;
    }
private:
    unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> map;
};
