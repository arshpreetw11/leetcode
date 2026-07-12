class Solution {
public:
    int ans=0;
    int dfs(int u,int parent,vector<vector<int>>& adj){
        int subTree=1;
        int firstChild=-1;
        bool good=true;
        for(int v:adj[u]){
            if(v==parent) continue;
            int child=dfs(v,u,adj);
            subTree+=child;
            if(firstChild==-1){
                firstChild=child;
            } else if(firstChild!=child) good=false;

        }
        if(good)ans++;
        return subTree;
    }
    int countGoodNodes(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<vector<int>> adj(n);
        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dfs(0,-1,adj);
        return ans;
    }
};