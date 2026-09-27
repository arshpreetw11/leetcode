class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        int i=0;
        string ans="";
        while(i<s.size()){
            if(s[i]==')'){
                string res="";
                while(st.top()!='('){
                    res+=st.top();
                    st.pop();
                }
                st.pop();
                //reverse(res.begin(),res.end());
                int idx=0;
                while(idx<res.size()){
                    st.push(res[idx]);
                    idx++;
                }

            }
            else
                st.push(s[i]);
            i++;
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};