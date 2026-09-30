class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        int n=s.size();
        for(char c:s){
            if(!st.empty() && st.top().first==c){
                st.top().second++;
                if(st.top().second==k){
                    st.pop();
                }
            }
            
            else{
                st.push({c,1});
            }
        }
        string ans="";
        while(!st.empty()){
            for(int i=0;i<st.top().second;i++){
                ans+=st.top().first;
            }
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};