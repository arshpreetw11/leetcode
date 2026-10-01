class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n=s.size();
        for(char c:s){
            if(c=='('|| c=='[' || c=='{'){
                st.push(c);
            }
            else{
                if(st.empty()) return false;
                char ch=st.top();
                if(ch=='(') {
                    if(c==')')
                    st.pop();
                    else
                    return false;
                }
                if(ch=='[') {
                    if(c==']')
                    st.pop();
                    else
                    return false;
                }
                if(ch=='{') {
                    if(c=='}')
                    st.pop();
                    else
                    return false;
                }
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};