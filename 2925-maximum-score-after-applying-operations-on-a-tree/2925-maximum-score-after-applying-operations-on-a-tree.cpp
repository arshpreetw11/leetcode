class Solution {
public:
    long long dfs(int u,int parent,vector<vector<int>>& adj,vector<int>& values){
        if(u!=0 && adj[u].size()==1) return values[u];
        long long keep=0;
        for(int v:adj[u]){
            if(v==parent) continue;
            keep+=dfs(v,u,adj,values);
        }
        return min((long long)values[u],keep);
    }
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n=values.size();
        vector<vector<int>> adj(n);
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        long long total=0;
        for(int x: values){
            total+=x;
        }
        int mn= dfs(0,-1,adj,values);
        return total-mn;
    }
};