#include<bits\stdc++.h>
using namespace std;
// class Solution {
// public:
//     vector<vector<string>> findLadders(string start, string end, vector<string> wordList) {
//         unordered_set<string> dict;
//         for (auto x : wordList)dict.insert(x);
//         if (!dict.count(end)) return vector<vector<string>>();
//         unordered_set<string> head={start}, tail={end};
//         vector<vector<string>> ans;
//         unordered_map<string, vector<string>> next;
//         bool head_start = true;
//         while (!head.empty() && !tail.empty()) {
//             for (auto word:head) dict.erase(word);
//             for (auto word:tail) dict.erase(word);
//             if (head.size() > tail.size()) {
//                 swap(head, tail);
//                 head_start = !head_start;
//             }
//             unordered_set<string> temp_head;
//             bool stop = false;
//             for (auto word:head) {
//                 string original_word = word;
//                 for (int i=0; i<word.length(); i++) {
//                     char temp = word[i];
//                     for (char ch='a'; ch<='z'; ch++) {
//                         if (ch == temp) continue;
//                         word[i] = ch;
//                         if (tail.find(word) != tail.end()) {
//                             stop = true;
//                             if (head_start)
//                                 next[original_word].push_back(word);
//                             else
//                                 next[word].push_back(original_word);
//                         }
//                         if (!stop && dict.find(word) != dict.end()) {
//                             temp_head.insert(word);
//                             if (head_start)
//                                 next[original_word].push_back(word);
//                             else
//                                 next[word].push_back(original_word);
//                         }
//                     }
//                     word = original_word;
//                 }
//             }
//             if (stop) break;
//             head = temp_head;
//         }
//         vector<string> v={start};
//         for (auto x : next){
//             cout<<x.first<<":"<<endl;
//             for (auto t : x.second)cout<<t<<endl;
//         }
//         dfs(ans, v, next, start, end);
//         return ans;
//     }
//
//     void dfs(vector<vector<string>> &ans, vector<string> &v, unordered_map<string, vector<string>> &next, string s, string t) {
//         if (s == t) {
//             ans.push_back(v);
//         }
//         for (auto word:next[s]) {
//             v.push_back(word);
//             dfs(ans, v, next, word, t);
//             v.pop_back();
//         }
//     }
// };
class Solution {
public:
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    vector<vector<string>> res;
    vector<string> tmp;
    unordered_set<string> head,tail;
    unordered_set<string> dic;
    unordered_map<string,vector<string>> next;
    bool search4ward = true;
    for (auto x:wordList)dic.insert(x);
    dic.erase(beginWord);
    if (!dic.count(endWord)) return res;
    head.insert(beginWord);
    tail.insert(endWord);
    get(next,head,tail,dic,search4ward);
    for (auto x: next){
        cout<<x.first<<":"<<endl;
        for (auto t: x.second)cout<<t<<endl;
    }
    tmp.push_back(beginWord);
    getPath(res,tmp,next,beginWord,endWord);
    return res;
}
void get(unordered_map<string,vector<string>>& next, unordered_set<string>& head, unordered_set<string>& tail,unordered_set<string>& dic, bool search4ward){
    if (head.size()> tail.size()) return get(next,tail,head,dic,!search4ward);
    if (!head.size()) return;
    bool done = false;
    unordered_set<string> immediate;
    for (auto x: head) dic.erase(x);
    for (auto word: head){
        int l = word.size();
        string temp = word;
        for (int i = 0; i < l ; i++){
            temp = word;
            for (int j = 0 ; j < 26;j++){
                temp[i]='a'+j;
                cout<<"**"<<temp<<endl;
                if (tail.count(temp)){
                    search4ward?next[word].push_back(temp):next[temp].push_back(word);
                    done = true;
                }
                else if (dic.count(temp)){
                    immediate.insert(temp);
                    search4ward?next[word].push_back(temp):next[temp].push_back(word);
                }
            }
        }
    }
if (!done) return get(next,immediate,tail,dic,search4ward);
}
void getPath(vector<vector<string>>& res,vector<string>& tmp, unordered_map<string,vector<string>>& next, string cur,string endWord){
    if (cur == endWord)res.push_back(tmp);
    else{
        for (auto x : next[cur]){
            tmp.push_back(x);
            getPath(res,tmp,next,x,endWord);
            tmp.pop_back();
        }
    }
}
};
int main()
{
    Solution p;
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    vector<vector<string>> res = p.findLadders("hit","cog",wordList);
    for (auto x: res){
        for (int i = 0 ; i < x.size();i++){
            if (i) cout<<"->";
            cout<<x[i];
        }
        cout<<endl;
    }
    return 0;
}
