class Solution {
public:

    int check(int l,int r,int k,vector<int> &slices){
        int m=r-l+1;
        vector<vector<int>> dp(m+1,vector<int>(k+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=k;j++){
                dp[i][j]=dp[i-1][j];
                if(i>=2){
                    dp[i][j]=max(dp[i][j],dp[i-2][j-1]+slices[i+l-1]);
                }else if(j==1){
                    dp[i][j]=max(dp[i][j],slices[l]);
                }
            }
        }
        return dp[m][k];
    }
    int maxSizeSlices(vector<int>& slices) {
        int n=slices.size();
        int k=n/3;
        int case1=check(0,n-2,k,slices);
        int case2=check(1,n-1,k,slices);
        return max(case1,case2);
    }
};