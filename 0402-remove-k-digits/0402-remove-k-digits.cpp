class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        stack<char> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top()>num[i] && k>0){
                st.pop();
                k--;
            }
            st.push(num[i]);

        }
        while(!st.empty() && k>0){
            st.pop();
            k--;
        }
        if(k>0) return "";
        string ans="";
        while(!st.empty()){
            ans.insert(ans.begin(),st.top());
            st.pop();
        }
        for(int i=0;i<ans.size();i++){
            if(ans[i]!='0') {
                return ans.substr(i);
            }
        }
        return "0";
    }
};