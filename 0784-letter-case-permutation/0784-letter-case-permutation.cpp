class Solution {
public:
void solve(int i,string &s,vector<string>& ans){
    if(i==s.size()){
        ans.push_back(s);
        return;
    }
    if(isdigit(s[i])){
        solve(i+1,s,ans);
        return ;
    }
    char ch=s[i];
    s[i]=tolower(ch);
    solve(i+1,s,ans);
    s[i]=toupper(ch);
    solve(i+1,s,ans);

}
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        solve(0,s,ans);
        return ans;
    }
};