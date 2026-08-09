class Solution {
public:
    vector<vector<int>> dp;
    vector<int> suffix;
    int n;
    int solve(int i,int M){
        if(i>=n) return 0;
        if(i+2*M>n) return suffix[i];
        if(dp[i][M]!=-1) return dp[i][M];
        int ans=0;
        for(int x=1;x<=2*M;x++){
            ans=max(ans,suffix[i]-solve(i+x,max(M,x)));
        }
        return dp[i][M]=ans;
    }
    int stoneGameII(vector<int>& piles) {
        n=piles.size();
        dp.assign(n+1,vector<int>(n+1,-1));
        suffix.assign(n,0);
        suffix[n-1]=piles[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i]=suffix[i+1]+piles[i];
        }
        int ans=solve(0,1);
        return ans;
    }
};