class Solution {
public:
int ans=1;
    int solve(int n,vector<vector<int>>& adj,vector<int>& vis,string& s){
        
        int largest=0,secondLargest=0;

        vis[n]=1;
        for(int x: adj[n]){
            if(vis[x]) continue;
            int len=solve(x,adj,vis,s);
            if(s[x]==s[n]) continue;
            if(len>largest){
                secondLargest=largest;
                largest=len;
            } else if(secondLargest<len){
                secondLargest=len;
            }
        }
        ans=max(ans,largest+secondLargest+1);
        return largest+1;
    }
    int longestPath(vector<int>& parent, string s) {
        int n=s.size();
        vector<vector<int>> adj(n);
        vector<vector<int>> edges;
        int p=0;
        for(int i=0;i<n;i++){
            if(parent[i]!=-1){
                edges.push_back({i,parent[i]});
            }else{
                p=i;
            }
        }
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n,0);
        int x=solve(p,adj,vis,s);
        
        return ans;
    }
};