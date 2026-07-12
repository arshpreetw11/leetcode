class Solution {
    private:
    void dfs(int node, vector<vector<int>> adj, vector<int>& vis) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, vis);
            }
        }
}
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        //basically we have to count the number of subgraphs.
        int pro=0,ones=0;
        int n=isConnected.size();
        
        vector<int> vis(n,0);
        vector<vector<int>> adj(n);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j){
                    if(isConnected[i][j]==1){
                        adj[i].push_back(j);
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                dfs(i,adj,vis);
                pro++;
            }
        }
        return pro;
    }
};