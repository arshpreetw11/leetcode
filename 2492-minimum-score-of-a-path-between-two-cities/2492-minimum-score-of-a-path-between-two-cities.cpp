class Solution {
public:
int ans=INT_MAX;
    void dfs(int u,vector<vector<pair<int,int>>>& adj,vector<bool>& vis){
        vis[u]=true; 

        for(auto& [v,w]:adj[u]){
            ans=min(ans,w);
            if(vis[v]==false)
            dfs(v,adj,vis);
        }
       }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto& road:roads){
            int u=road[0];
            int v=road[1];
            int w=road[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        if(adj[1].empty()) return 0;
        vector<bool> vis(n+1,false);
        dfs(1,adj,vis);
        return ans;

    }
};