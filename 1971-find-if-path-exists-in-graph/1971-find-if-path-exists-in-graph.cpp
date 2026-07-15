class Solution {
public:
    bool dfs(int src,int dest,int n,vector<vector<int>>& adj,vector<int>& vis){
        if(src==dest) return true;
        vis[src]=1;
        for(int v: adj[src]){
            if(!vis[v]){
                if(dfs(v,dest,n,adj,vis))
                    return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto &e : edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n,0);
        return dfs(source,destination,n,adj,vis);
    }
};