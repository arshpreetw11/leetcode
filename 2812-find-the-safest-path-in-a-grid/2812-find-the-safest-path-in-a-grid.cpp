class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int,int>> q;
        vector<vector<int>> dist(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    dist[i][j]=0;
                }
            }
        }

        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,1,-1};
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();

            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];

                if(nx>=0 && ny>=0 && nx<n && ny<n){
                    if(dist[nx][ny]==-1){
                        dist[nx][ny]=dist[x][y]+1;
                        q.push({nx,ny});
                    }
                }
            }
        }
        priority_queue<tuple<int,int,int>> pq;
        vector<vector<int>> best(n,vector<int>(n,-1));
        best[0][0]=dist[0][0];
        pq.push({dist[0][0],0,0});
        while(!pq.empty()){
            auto [safe,x,y]=pq.top();
            pq.pop();
            if(x==n-1 && y==n-1) return safe;
            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx>=0 && ny>=0 && nx<n && ny<n){
                    int mn=min(safe,dist[nx][ny]);
                    if(mn>best[nx][ny]){
                        best[nx][ny]=mn;
                        pq.push({mn,nx,ny});
                    }
                    
                }

            }
        }
        return 0;
    }
};