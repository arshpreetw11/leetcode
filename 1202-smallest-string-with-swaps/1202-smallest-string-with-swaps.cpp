class Solution {
public:
    void dfs(int u,vector<vector<int>>& graph,vector<int>& vis,vector<int>& nodes){
        vis[u]=1;
        nodes.push_back(u);
        for(int v: graph[u]){
            if(!vis[v])
                dfs(v,graph,vis,nodes);
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        vector<vector<int>> graph(s.size());
        int n=s.size();
        for(auto &p:pairs){
            int u=p[0];
            int v=p[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            vector<int> nodes;
            dfs(i,graph,vis,nodes);
            string chars;
            for(int idx: nodes){
                chars+=s[idx];
            }
            sort(nodes.begin(),nodes.end());
            sort(chars.begin(),chars.end());

            for(int j=0;j<nodes.size();j++){
                s[nodes[j]]=chars[j];
            }
        }
        return s;
    }
};