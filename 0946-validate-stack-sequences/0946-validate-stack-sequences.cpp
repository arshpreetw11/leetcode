class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i=0;
        int j=0;
        int n=pushed.size();
        stack<int> st;
        while(i<n){
            if(st.empty()){
                st.push(pushed[i]);
                i++;
            }else{
                if(popped[j]==st.top()){
                    st.pop();
                    j++;
                }else{
                    st.push(pushed[i]);
                    i++;
                }
            }
        }
        while(!st.empty()){
            if(popped[j]!=st.top())
                return false;
            st.pop();
            j++;
        }
        return true;
    }
};