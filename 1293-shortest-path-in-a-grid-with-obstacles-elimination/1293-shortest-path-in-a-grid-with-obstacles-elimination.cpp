class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<bool>>> vis(m,vector<vector<bool>>(n,vector<bool>(k+1,false)));
        vis[0][0][k]=true;
        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,1,0,-1};
        queue<tuple<int,int,int>> q;
        q.push({0,0,k});
        int steps=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto [x,y,rem]=q.front();
                q.pop();
                if(x==m-1 && y==n-1) return steps;

                for(int d=0;d<4;d++){
                    int nx=x+dx[d];
                    int ny=y+dy[d];
                    if(nx>=0 && ny>=0 && nx<m && ny<n){
                        if(grid[nx][ny]==0){
                            if(!vis[nx][ny][rem]){
                                vis[nx][ny][rem]=true;
                                q.push({nx,ny,rem});
                            }
                        }
                        else if(rem>0){
                            if(!vis[nx][ny][rem-1]){
                                vis[nx][ny][rem-1]=true;
                                q.push({nx,ny,rem-1});
                            }
                        }
                    }
                }
                
            }
            
            steps++;

        }
        return -1;
        
    }
};