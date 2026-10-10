class Solution {
public:
vector<vector<int>> adj;
int mx=0;
    void dfs(int i,int cnt,vector<int> &vis,vector<int>&scores,int s){
        vis[i]=1;
        cnt++;
        s+=scores[i];
        if(cnt==4){
            mx=max(mx,s);
            vis[i]=0;
            return;
        }
        for(int v:adj[i]){
            if(!vis[v]){
                dfs(v,cnt,vis,scores,s);
            }
        }
        vis[i]=0;
    }
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        int nodes=scores.size();
        adj.resize(nodes);
        for(auto &e: edges){
            int u=e[0],v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=0;i<nodes;i++){
            sort(adj[i].begin(), adj[i].end(), [&](int a, int b) {
                return scores[a] > scores[b];
            });
            if(adj[i].size()>3){
                adj[i].resize(3);
            }
        }
        for(auto &e : edges) {
            int b = e[0];
            int c = e[1];
            for(int a : adj[b]) {
                if(a == c) continue;
                for(int d : adj[c]) {
                    if(d == b || d == a) continue;
                    mx = max(mx,
                             scores[a] + scores[b] +
                             scores[c] + scores[d]);
                }
            }
        }
        return (mx==0)?-1:mx;
    }
};