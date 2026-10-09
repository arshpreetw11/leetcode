class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int check(int i,int prev_col,vector<vector<int>>&grid){
        if(i==n){
            return 0;
        }
        if(dp[i][prev_col+1]!=INT_MAX) return dp[i][prev_col+1];
        int mn=INT_MAX;
        for(int c=0;c<n;c++){
            if(prev_col==c) continue;
            mn=min(mn,grid[i][c]+check(i+1,c,grid));
        }
        return dp[i][prev_col+1]=mn;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        n=grid.size();
        dp.resize(n,vector<int>(n+1,INT_MAX));
        return check(0,-1,grid);
    }
};