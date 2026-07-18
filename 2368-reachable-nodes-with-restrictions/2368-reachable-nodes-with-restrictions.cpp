class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>>  adj(n);
        for(auto &e: edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        unordered_set<int> res(restricted.begin(),restricted.end());
        int nodes=0;
        vector<int> vis(n,0);
        int ans=1;
        queue<int> q;
        q.push(0);
        vis[0]=1;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int i=q.front();
                q.pop();
                for(int v:adj[i]){
                    if(!vis[v] && !res.count(v)){
                        vis[v]=1;
                        q.push(v);
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};