/* leetcode test code */
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>
#include <climits>
#include <string>
using namespace std;
string to_string(int a){
    stringstream ss;
    ss << a;
    return ss.str();
}
struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 int remove(string & s){
     int flag = 0;
     for (int i = 0 ; i < s.size()-1;++i){
         if (s[i] == '(' && s[i+1] == ')'){
             flag = 1;
             s.erase(i,2);
             break;
         }
     }
     return flag;
 }
string trans(TreeNode* t){
    if (!t) return "()";
    return to_string(t->val)+'('+trans(t->left)+trans(t->right)+')';
}
int main(int argc, char const *argv[])
{
    TreeNode * head = new TreeNode(0);
    head->left = new TreeNode(1);
    head->right = new TreeNode(2);
    string tmp = trans(head);
    string test = "asdfasdg";
    while(remove(tmp));
    cout<<tmp<<endl;
}
