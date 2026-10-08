class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string res="",sub="";
        for(char ch:s){
            if(ch=='('){
                st.push(ch);
                sub+=ch;
            }else{
                st.pop();
                sub+=ch;
                if(st.empty()){
                    res+=sub.substr(1,sub.size()-2);
                    sub="";
                }
            }
        }
        return res;
    }
};