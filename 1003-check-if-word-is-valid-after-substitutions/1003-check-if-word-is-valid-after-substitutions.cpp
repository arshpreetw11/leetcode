class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c:s){
            if(c=='c'){
                if(st.empty()) return false;
                else{
                    if(st.size()>=2){
                        if(st.top()=='b'){
                            st.pop();
                            if(st.top()=='a'){
                                st.pop();
                            }
                            else return false;
                        }else return false;
                    }
                    else return false;
                }
            }else st.push(c);
        }
        
        return (st.empty());
    }
};