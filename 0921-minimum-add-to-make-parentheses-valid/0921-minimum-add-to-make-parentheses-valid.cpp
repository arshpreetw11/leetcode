class Solution {
public:
    int minAddToMakeValid(string s) {
        int i=0;
        stack<char> st;
        
        while(i<s.size() ){
            if(s[i]==')'){
                if(!st.empty() && st.top()=='('){
                    st.pop();
                }else {
                    st.push(s[i]);
                }
            }else{
                st.push(s[i]);
            }
            i++;
        }
        return st.size();
    }
};