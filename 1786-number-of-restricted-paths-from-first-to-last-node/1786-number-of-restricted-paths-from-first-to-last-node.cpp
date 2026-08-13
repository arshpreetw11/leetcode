class Solution {
public:
const int mod=1e9+7;
    int check(int u,vector<vector<pair<int,int>>>& adj,vector<int>&dist,vector<int>& dp){
        if(u==(int)adj.size()-1)
            return 1;
        if(dp[u]!=-1){
            return dp[u];
        }
        int ans=0;
        for(auto &a:adj[u]){
            int v=a.first;
            if(dist[u]>dist[v]){
                ans+=check(v,adj,dist,dp);
                ans%=mod;
            }
        }
        return dp[u]=ans;
    }
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n+1);
        
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            int w=e[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<int> dist(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        dist[n]=0;
        pq.push({0,n});

        while(!pq.empty()){
            auto [d,u]=pq.top();
            pq.pop();

            if(dist[u]<d)
                continue;
            for(auto &[v,w]:adj[u]){
                if(dist[v]>d+w){
                    dist[v]=d+w;
                    pq.push({dist[v],v});
                }
            }
        }
        vector<int> dp(n+1,-1);
        return check(1,adj,dist,dp);
    }
};