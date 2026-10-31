class Solution {
public:
    int dx[2]={0,1};
    int dy[2]={1,0};
    int m,n,ans=0;
    int mod=1e9+7;
    vector<vector<vector<int>>> dp;
    int dfs(int i,int j,bool prevright,vector<vector<int>>& grid){
        if(i>=m || j>=n) return 0;
        
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(dp[i][j][prevright]!=-1) return dp[i][j][prevright];
        int ways;
        if(grid[i][j]==1){
            if(prevright){
                int x=i,y=j+1;
                ways=dfs(x,y,false,grid);
            }else{
                int x=i+1,y=j;
                ways=dfs(x,y,true,grid);
            }
        }else{
            int w1=dfs(i+1,j,true,grid);
            int w2=dfs(i,j+1,false,grid);
            ways=(w1+w2)%mod;
        }
        return dp[i][j][prevright]=ways;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        m=grid.size(),n=grid[0].size();
        //right and down;
        dp.resize(m,vector<vector<int>>(n,vector<int>(2,-1)));
        int a=dfs(0,0,false,grid);
        return a;
    }
};