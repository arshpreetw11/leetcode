class Solution {
public:
    unordered_set<string> vis;
    string ans;

    void dfs(string start,int k){
        for(int x=0;x<k;x++){
            string s=start+char('0'+x);
            if(!vis.count(s)){
                vis.insert(s);
                dfs(s.substr(1),k);
                ans.push_back(char('0'+x));
            }
        }
    }
    string crackSafe(int n, int k) {
        string start(n-1,'0');
        dfs(start,k);
        return ans+start;
    }
};