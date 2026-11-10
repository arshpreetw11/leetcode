class Solution {
public:
    vector<long long> dp;
    int climb(int i,int j,vector<int> &costs,int n){
        if(j>=n) return 0;
        if(dp[j]!=INT_MAX) return dp[j];
        int ans=INT_MAX;
        for(int k=1;k<=3;k++){
            if(j+k<=n){
                int cost=(j+k==n)?0:costs[j+k-1];
                int x=k*k+cost+climb(j,j+k,costs,n);
                ans=min(ans,x);
            }
        }
        return dp[j]=ans;
    }
    int climbStairs(int n, vector<int>& costs) {
        dp.assign(n+1,1e18);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            int cost=costs[i-1];
            for(int k=1;k<=3;k++){
                if(i-k>=0){
                    long long jump=(long long)k*k+cost+dp[i-k];
                    dp[i]=min(dp[i],jump);
                }
            }
        }
        return dp[n];
    }
};