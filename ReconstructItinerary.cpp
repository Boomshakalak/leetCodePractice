/*
    I was trying to build a full dfs method but finally get TLE since I will get different possible paths using NO MORE THAN the current availabe tickets
    The problem here is that the tickets should all be used up since we assume the owner is not a stuipid one that will waste the tickets
    And the multiset is garuanteed the tickets are used in lexial order and we allow duplicates in multiset
*/
class Solution {
    public:
vector<string> findItinerary(vector<pair<string, string>> tickets) {
    for (auto ticket : tickets)
        targets[ticket.first].insert(ticket.second);
    visit("JFK");
    return vector<string>(route.rbegin(), route.rend());
}

map<string, multiset<string>> targets;
vector<string> route;

void visit(string airport) {
    while (targets[airport].size()) {
        string next = *targets[airport].begin();
        targets[airport].erase(targets[airport].begin());
        visit(next);
    }
    route.push_back(airport);
}

};
