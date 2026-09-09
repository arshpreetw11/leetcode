class Solution {
public:
vector<int> parent,rank;
    int find(int x){
        if(parent[x]==x)
            return x;
        return parent[x]=find(parent[x]);
    }
    bool unite(int a,int b){
        a=find(a);
        b=find(b);
        if(a==b) return false;
        if(rank[a]<rank[b]) 
            swap(a,b);
        parent[b]=a;
        if(rank[a]==rank[b]) rank[a]++;
        return true;
    }
    int minCost(int n, vector<vector<int>>& edges, int k) {
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        vector<vector<int>> adj(n);
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            int w=e[2];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int comp=n;
        sort(edges.begin(),edges.end(),[&](vector<int>& a,vector<int>& b){
            return a[2]<b[2];
        });
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            int w=e[2];
            if(unite(u,v)){
                comp--;
                if(k==comp)
                    return w;}
        }
        return 0;
    }
};