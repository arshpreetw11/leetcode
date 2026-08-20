class Solution {
public:
vector<int> count;
vector<int> arr;
    void df1(int u,int parent,vector<vector<int>>& adj){
        count[u]=1;
        for(int v:adj[u]){
            if(v==parent) continue;

            df1(v,u,adj);
            count[u]+=count[v];
            arr[0]+=count[v];
        }
    }
    void df2(int u,int parent,vector<vector<int>>&adj,int n){
        for(int v:adj[u]){
            if(v==parent) continue;
            arr[v]=arr[u]+n-2*count[v];
            df2(v,u,adj,n);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        count.resize(n);
        arr.resize(n,0);
        df1(0,-1,adj);
        df2(0,-1,adj,n);
        return arr;
    }
};