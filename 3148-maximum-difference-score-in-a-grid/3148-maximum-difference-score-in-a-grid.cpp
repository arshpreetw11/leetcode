class Solution {
public:
    int ans=INT_MIN;
    int dx[2]={0,1};
    int dy[2]={1,0};
    int m,n;
    void dfs(vector<vector<int>>& grid,int x,int y,int score){
        
        for(int d=0;d<2;d++){
            int nx=x+dx[d];
            int ny=y+dy[d];
            if(nx<0 || ny<0 || nx>=m || ny>=n) continue;
            int s=grid[nx][ny]-grid[x][y];
            int newscore=score+s;
            ans=max(ans,newscore);
            dfs(grid,nx,ny,newscore);
        }
    }
    int maxScore(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         dfs(grid,i,j,0);
        //     }
        // }
        // return ans;

        vector<vector<int>> mn(m,vector<int>(n,INT_MAX));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i>0){
                    mn[i][j]=min(mn[i][j],mn[i-1][j]);
                }
                if(j>0){
                    mn[i][j]=min(mn[i][j],mn[i][j-1]);
                }
                if(mn[i][j]!=INT_MAX){
                    ans=max(ans,grid[i][j]-mn[i][j]);
                }
                mn[i][j]=min(grid[i][j],mn[i][j]);
            }
        }
        return ans;
    }
};