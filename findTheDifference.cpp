class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> map;
        for (auto x :s) map[x]++;
        for (auto x: t) {
            if (map.count(x)){
                map[x]--;
                if (!map[x])map.erase(x);
            }
            else return x;
        }
        return 'a';
    }
};
