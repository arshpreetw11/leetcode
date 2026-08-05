class Solution {
public:
vector<int> sz;
    int dfs(int u,vector<vector<int>>& adj){
        sz[u]=1;
        for(int v: adj[u]){
            sz[u]+=dfs(v,adj);
        }
        return sz[u];
    }
    int countHighestScoreNodes(vector<int>& parents) {
        int n=parents.size();
        vector<vector<int>> adj(n);
        for(int i=1;i<n;i++){
            if(parents[i]!=-1)
            adj[parents[i]].push_back(i);
        }
        sz.assign(n,0);
        dfs(0,adj);
        long long mx=0;
        int ans=0;
        for(int i=0;i<n;i++){
            long long score=1;
            int rem=n-sz[i];
            if(rem>0){
                score*=rem;
            }
            for(int child : adj[i]){
                score*=sz[child];
            }
            if(mx<score){
                mx=score;
                ans=1;
            }else if(mx==score){
                ans++;
            }
        }
        return ans;
    }
};