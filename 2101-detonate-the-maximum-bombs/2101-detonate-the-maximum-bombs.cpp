class Solution {
public:
    int dfs(int u,vector<vector<int>>& adj,vector<int>& vis){
        vis[u]=1;
        int cnt=1;
        for(int v:adj[u]){
            if(!vis[v]){
                cnt+=dfs(v,adj,vis);
            }
        }
        return cnt;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();//number of circles;
        vector<vector<int>> adj(n);
        int mx=0;
        for(int i=0;i<n;i++){
            long long r=bombs[i][2];
            for(int j=0;j<n;j++){
                long long dx=bombs[i][0]-bombs[j][0];
                long long dy=bombs[i][1]-bombs[j][1];
                long long dist=dx*dx+dy*dy;
                if(dist<=r*r){
                    adj[i].push_back(j);
                }
            }
        }
        for(int i=0;i<n;i++){
            vector<int> vis(n,0);
            int cnt=dfs(i,adj,vis);
            mx=max(mx,cnt);
        }
        return mx;
    }
};