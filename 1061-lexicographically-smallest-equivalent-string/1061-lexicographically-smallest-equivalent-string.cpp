class Solution {
public:
    void dfs(int i,vector<vector<int>>& adj,int &mn,vector<int>& vis){
        if(i>=26) return;
        vis[i]=1;
        mn=min(mn,i);
        for(int v:adj[i]){
            if(!vis[v]){
                dfs(v,adj,mn,vis);
            }
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n=s1.size();
        vector<vector<int>> adj(26);
        for(int i=0;i<n;i++){
            int a=s1[i]-'a';
            int b=s2[i]-'a';
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for(int i=0;i<baseStr.size();i++){
            int x=baseStr[i]-'a';
            vector<int> vis(26,0);
            dfs(baseStr[i]-'a',adj,x,vis);
            baseStr[i]=x+'a';
        }
        return baseStr;
    }
};