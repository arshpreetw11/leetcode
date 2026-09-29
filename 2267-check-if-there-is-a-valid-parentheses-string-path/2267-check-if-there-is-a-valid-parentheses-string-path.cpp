class Solution {
public:
int dx[2]={0,1};
int dy[2]={1,0};
int m,n;
vector<vector<vector<char>>> dp;
//vector<vector<vector<bool>>> dp;
//directions->down/right;

    bool check(int x,int y,vector<vector<char>>& grid,int count){
        if(count<0) return false;
        int rem=(m-1-x)+(n-1-y);
        if(count>rem) return false;

        if(x==m-1 && y==n-1 )
            return count==0;
        if(dp[x][y][count]!=-1) return dp[x][y][count];
        
        bool ans = false;

        if (x + 1 < m) {
            int nb = count + (grid[x + 1][y] == '(' ? 1 : -1);
            ans |= check(x + 1, y, grid,nb);
        }

        if (y + 1 < n) {
            int nb = count + (grid[x][y + 1] == '(' ? 1 : -1);
            ans |= check(x, y + 1, grid,nb);
        }

        return dp[x][y][count] = ans;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        
        m=grid.size(),n=grid[0].size();
        int len=m+n-1;
        if(len%2) return false;
        if(grid[0][0]==')' || grid[m-1][n-1]=='(') return false;

        dp.assign(m, vector<vector<char>>(n, vector<char>(len + 1, -1)));
        //memset(dp,-1,sizeof(dp));
        return check(0,0,grid,1);
    }
};