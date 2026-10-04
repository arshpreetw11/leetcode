class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> grid(n,vector<int>(n,1));
        for(auto &m:mines){
            int i=m[0];
            int j=m[1];
            grid[i][j]=0;
        }
        vector<vector<int>> up(n,vector<int>(n,0)),down(n,vector<int>(n,0)),right(n,vector<int>(n,0)),left(n,vector<int>(n,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    if(i==0) up[i][j]=1;
                    else up[i][j]=up[i-1][j]+1;

                    if(j==0) left[i][j]=1;
                    else left[i][j]=1+left[i][j-1];
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(grid[i][j]==1){
                    if(i==n-1) down[i][j]=1;
                    else down[i][j]=1+down[i+1][j];

                    if(j==n-1) right[i][j]=1;
                    else right[i][j]=1+right[i][j+1];
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int order=min({up[i][j],down[i][j],left[i][j],right[i][j]});
                ans=max(ans,order);
            }
        }
        return ans;
    }
};