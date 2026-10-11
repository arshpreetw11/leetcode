class Solution {
public:
vector<vector<int>> adj;
    bool found(int u,int v){
        if(adj[u].size()==0) return false;
        for(int x:adj[u]){
            if(x==v) return true;
            if(found(x,v)) return true;
        }
        return false;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n=queries.size();
        vector<bool> ans(n,false);
        if(prerequisites.size()==0) return ans;
        adj.resize(numCourses);
        for(auto &pre: prerequisites){
            int u=pre[0];
            int v=pre[1];
            adj[u].push_back(v);
        }
        int i=0;
        for(auto &q:queries){
            int u=q[0];
            int v=q[1];
            if(found(u,v)){
                ans[i]=true;
            }
            i++;
        }
        return ans;
    }
};