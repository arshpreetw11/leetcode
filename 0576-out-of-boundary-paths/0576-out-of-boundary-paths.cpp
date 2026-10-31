class Solution {
public:
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
vector<vector<vector<int>>> dp;
int mod=1e9+7;
    int count(int i,int j,int m,int n,int move){
        if(i>=m || j>=n || i<0 || j<0){
            return 1;
        }
        if(move==0) return 0;
        if(dp[i][j][move]!=-1) return dp[i][j][move];
        long long total=0;
        for(int d=0;d<4;d++){
            int x=i+dx[d];
            int y=j+dy[d];
            total=(total+count(x,y,m,n,move-1))%mod;
        }
        return dp[i][j][move]=total;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        dp.assign(m,vector<vector<int>>(n,vector<int>(maxMove+1,-1)));
        //up right down left;
        return count(startRow,startColumn,m,n,maxMove);
    }
};