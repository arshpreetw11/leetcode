class Solution {
public:
int m,n;
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2,int i,int j,vector<vector<int>>&vis){
        
        vis[i][j]=1;
        bool valid=(grid1[i][j]==1);
        for(int d=0;d<4;d++){
            int x=i+dx[d];
            int y=j+dy[d];
            if(x>=0 && y>=0 && x<m && y<n){
                if(!vis[x][y] && grid2[x][y]==1){
                    bool temp=dfs(grid1,grid2,x,y,vis);
                    valid&=temp;
                }
            }
        }
        return valid;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m=grid1.size(),n=grid1[0].size();
        int ans=0;
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j] || grid2[i][j]==0) continue;
                if(dfs(grid1,grid2,i,j,vis)) ans++;
            }
        }
        return ans;
    }
};