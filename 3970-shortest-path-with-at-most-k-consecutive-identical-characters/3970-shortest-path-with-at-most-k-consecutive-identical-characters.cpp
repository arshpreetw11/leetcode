class Solution {
public:
int mn=INT_MAX;
    // void dfs(int u,int v,vector<vector<pair<int,int>>>&adj,vector<int>& vis,string labels,int k,int same,char prev,int path){
    //     if(u==v){
    //         mn=min(mn,path);
    //         return ;
    //     }
    //     vis[u]=1;
    //     if(prev=='\0') prev=labels[u];
    //     for(auto &[i,w]:adj[u]){
    //         if(vis[i]) continue;
    //         int newSame=same;
    //         if(labels[i]==prev){
    //             newSame++;
    //         }else{
    //             newSame=1;
    //         }
    //         if(newSame>k) continue;
    //         dfs(i,v,adj,vis,labels,k,newSame,labels[i],path+w);

    //     }
    //     vis[u]=0;
    // }
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &e:edges){
            int u=e[0],v=e[1],w=e[2];
            adj[u].push_back({v,w});
        }
        vector<vector<long long>> dist(n,vector<long long>(k+1,LLONG_MAX));
        priority_queue<
            tuple<long long,int,int>,
            vector<tuple<long long,int,int>>,
            greater<tuple<long long,int,int>>
        > pq;
        dist[0][1]=0;
        pq.push({0,0,1});
        while(!pq.empty()){
            auto [d,u,same]=pq.top();
            pq.pop();
            if(d!=dist[u][same]) continue;
            if(u==n-1) return (int)d;

            for(auto &[v,w]: adj[u]){
                int cnt=(labels[u]==labels[v])?same+1:1;
                if(cnt>k) continue;
                if(d+w<dist[v][cnt]){
                    dist[v][cnt]=d+w;
                    pq.push({d+w,v,cnt});
                }
            }
        }
        return -1;
        // int same=1;
        // char prev='\0';
        // vector<int> vis(n,0);
        // dfs(0,n-1,adj,vis,labels,k,same,prev,0);
        // return (mn==INT_MAX)?-1:mn;
    }
};