class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n=coins.size();
        vector<vector<int>> adj(n);
        vector<int> degree(n);
        for(auto &e: edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }
        int num_coins=0;
        for(int c: coins){
            if(c) num_coins++;
        }
        if(num_coins==0) return 0;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(degree[i]==1){
                if(coins[i]==0){
                    q.push(i);
                }
            }
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();

            degree[u]--;
            for(int v:adj[u]){
                if(degree[v]==0) continue;
                degree[v]--;
                if(degree[v]==1 && coins[v]==0){
                    q.push(v);
                }
            }
        }
        while(!q.empty()) q.pop();

        for(int i=0;i<n;i++){
            if(degree[i]==1){
                q.push(i);
            }
        }
        for(int r=0;r<2;r++){
            int sz=q.size();
            while(sz--){
                int u=q.front();
                q.pop();

                degree[u]--;
                for(int v: adj[u]){
                    if(degree[v]==0) continue;
                    degree[v]--;
                    if(degree[v]==1 ){
                        q.push(v);
                    }
                }
            }
        }
        int rem=0;
        for(int i=0;i<n;i++){
            rem+=degree[i];
        }
        return (rem>=0)?rem:0;
    }
};