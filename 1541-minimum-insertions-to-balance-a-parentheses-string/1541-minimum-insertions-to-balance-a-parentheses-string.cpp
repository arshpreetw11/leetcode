class Solution {
public:
    int minInsertions(string s) {
        stack<char> st;
        int n=s.size();
        int add=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push('(');
            }else{
                if(st.empty()){
                    if(i!=s.size()-1 && s[i+1]==')'){
                        add++;
                        i++;
                    }else{
                        add+=2;
                    }
                }else{
                    if(i!=s.size()-1 && s[i+1]==')'){
                        st.pop();
                        i++;
                    }else{
                        add++;
                        st.pop();
                    }
                }
            }
        }
        return add+st.size()*2;
    }
};