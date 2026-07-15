class Solution {
public:
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
vector<vector<int>> border,vis;
    void dfs(int x,int y,int c,int m,int n,vector<vector<int>>& grid){
        vis[x][y]=1;
        if(x==0 || y==0 || x==m-1 || y==n-1){
            border[x][y]=1;
        }
        for(int k=0;k<4;k++){
            int nx=x+dx[k];
            int ny=y+dy[k];
            if(nx<0 || nx>=m || ny<0 || ny>=n){
                border[x][y]=1;
            }
            else if(grid[nx][ny]!=c){
                border[x][y]=1;
            }
            else if(!vis[nx][ny]){
                dfs(nx,ny,c,m,n,grid);
            }
        }
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int m=grid.size(),n=grid[0].size();
        int org=grid[row][col];
        border.resize(m,vector<int>(n,0));
        vis.resize(m,vector<int>(n,0));
        dfs(row,col,org,m,n,grid);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(border[i][j]) grid[i][j]=color;
            }
        }
        return grid;
    }
};