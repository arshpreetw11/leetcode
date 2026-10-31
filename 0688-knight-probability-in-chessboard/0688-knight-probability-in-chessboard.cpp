class Solution {
public:
int dx[8]={-2,-2,-1,-1,1,1,2,2};
int dy[8]={-1,1,-2,2,-2,2,-1,1};
vector<vector<vector<double>>> dp;
    double dfs(int r,int c,int n,int k){
        if(r<0 ||c<0 ||r>=n || c>=n) return 0.0;
        if(dp[r][c][k]!=-1.0) return dp[r][c][k];
        if(k==0) return 1.0;
        double total=0.0;
        for(int i=0;i<8;i++){
            total+=dfs(r+dx[i],c+dy[i],n,k-1);
        }
        return dp[r][c][k]=total/8.0;
    }
    double knightProbability(int n, int k, int row, int column) {
        //n*n chessboard. row,column -> startPoint  k->moves. 8 possible moves;
        dp.assign(n,vector<vector<double>>(n,vector<double>(k+1,-1.0)));
        return dfs(row,column,n,k);
    }
};