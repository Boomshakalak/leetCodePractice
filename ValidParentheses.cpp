class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        if (s[0]!= '[' && s[0]!='{' && s[0]!='(') return false;
        for (auto x : s){
            if (x=='(' || x =='{' || x=='['){
                st.push(x);
                continue;}
                switch(x){
                    case ']': {if (st.empty()||st.top()!='[') return false;
                    st.pop();
                    break;}
                    case ')': {if (st.empty()||st.top()!='(') return false;
                    st.pop();
                    break;}
                    case '}': {if (st.empty()||st.top()!='{') return false;
                    st.pop();
                    break;}
                }
            
        }
        if (st.empty()) return true;
            else return false;
    }
};