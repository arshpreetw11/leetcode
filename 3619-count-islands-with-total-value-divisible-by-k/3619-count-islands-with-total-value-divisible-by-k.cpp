class Solution {
public:
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int m,n;
    long long dfs(vector<vector<int>>& grid, int i,int j,vector<vector<int>>& vis){
        if(i<0 || j<0 || i>=m || j>=n) return 0;
        if(grid[i][j]==0 || vis[i][j]) return 0;
        vis[i][j]=1;
        long long sum=grid[i][j];
        for(int d=0;d<4;d++){
            int x=i+dx[d];
            int y=j+dy[d];
            sum+=dfs(grid,x,y,vis);
        }
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        m=grid.size(),n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        long long ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j] || grid[i][j]==0) continue;
                long long sum=dfs(grid,i,j,vis);
                if(sum%k==0) ans++;
            }
        }
        return ans;
    }
};