class Solution {
public:
    unordered_set<string> st;
    void dfs(string &s,int idx,int left,int right,int balance,string curr){
        if(balance<0) return ;
        if(idx==s.size()){
            if(left==0 && right ==0 && balance==0){
                st.insert(curr);
            }
            return;
        }
        char c=s[idx];
        if(c!='(' && c!=')'){
            dfs(s,idx+1,left,right,balance,curr+c);
            return;
        }
        if(c=='(' && left>0){
            dfs(s,idx+1,left-1,right,balance,curr);
        }
        if(c==')' && right>0){
            dfs(s,idx+1,left,right-1,balance,curr);
        }

        if(c=='('){
            dfs(s,idx+1,left,right,balance+1,curr+c);
        }else{
            dfs(s,idx+1,left,right,balance-1,curr+c);
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int n=s.size();
        int left=0;
        int right=0;

        for(char c:s){
            if(c=='(') left++;
            else if(c==')'){
                if(left>0) left--;
                else right++;
            }
        }
        string curr="";
        dfs(s,0,left,right,0,curr);
        return vector<string>(st.begin(),st.end());
    }
};