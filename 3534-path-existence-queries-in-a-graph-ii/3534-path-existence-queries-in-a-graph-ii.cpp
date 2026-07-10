class Solution {
public:
int x=0;
    int path(int u,int v,vector<vector<int>>& adj){
        vector<int> vis(adj.size(),0);
        queue<pair<int,int>> q;
        vis[u]=1;
        q.push({u,0});
        while(!q.empty()){
            auto [node,d]=q.front();
            q.pop();

            if(node==v) return d;
            for(int next:adj[node]){
                if(!vis[next]){
                vis[next]=1;
                q.push({next,d+1});}
            }
        }
        return -1;
    }
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> order(n);
        for(int i=0;i<n;i++){
            order[i]=i;
        }
        sort(order.begin(),order.end(),[&](int a,int b){
            return nums[a]<nums[b];
        });
        vector<int> pos(n);

        for(int i=0;i<n;i++)
            pos[order[i]]=i;
        

        // vector<vector<int>> adj(n);
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         int u=order[i];
        //         int v=order[j];
        //         int val1=nums[u];
        //         int val2=nums[v];
        //         if(abs(val1-val2)<=maxDiff){
        //                 adj[u].push_back(v);
        //                 adj[v].push_back(u);
        //         }
        //     }
        // }
        vector<int> nxt(n);
        int j=0;
        for(int i=0;i<n;i++){
            while(j+1<n && nums[order[j+1]]-nums[order[i]]<=maxDiff){
                j++;
            }
            nxt[i]=j;
        }
        
        vector<vector<int>> up(20,vector<int>(n,0));
        for(int i=0;i<n;i++){
            up[0][i]=nxt[i];
        }
        for(int k=1;k<20;k++){
            for(int i=0;i<n;i++){
                up[k][i]=up[k-1][up[k-1][i]];
            }
        }
        vector<int> res;
        for(auto &q : queries){
            int u=q[0];
            int v=q[1];
            int l=pos[u];
            int r=pos[v];
            if (l == r) {
                res.push_back(0);
                continue;
            }
            if(l>r){
                swap(l,r);
            }
            int curr=l;
            int ans=0;
            for(int k=19;k>=0;k--){
                if(up[k][curr] > curr && up[k][curr]<r){
                    curr=up[k][curr];
                    ans+=(1<<k);
                }
            }
            if (up[0][curr] == curr) {
                res.push_back(-1);
                continue;
            }
            curr = up[0][curr];
            ans++;
            if(curr>=r){
                res.push_back(ans);
            }else res.push_back(-1);
        }
        return res;
    }
};