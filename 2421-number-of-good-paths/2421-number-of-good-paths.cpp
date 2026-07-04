class Solution {
public:
int path=0;
vector<int> parent;
    int find(int x){
        if(parent[x]==x){
            return x;
        }
        return parent[x]=find(parent[x]);
    }
    
    void Union(int a,int b){
        int pa=find(a);
        int pb=find(b);
        if(pa!=pb){
            parent[pa]=pb;
        }
    }
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n=vals.size();
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        vector<vector<int>> adj(n);
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        map<int,vector<int>> nodes;
        for(int i=0;i<n;i++){
            nodes[vals[i]].push_back(i);
        }
        int ans=0;
        for(auto &[value,vec]:nodes){
            for(int u:vec){
                for(int v:adj[u]){
                    if(vals[v]<=value){
                        Union(u,v);
                    }
                }
            }
            unordered_map<int,int> mp;
            for(int u:vec){
                mp[find(u)]++;
            }
            for(auto & [root,k]:mp){
                ans+=k*(k+1)/2;
            }
        }
        return ans;
    }
    
};