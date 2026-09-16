class Solution {
public:
    int numberOfSets(int n, int k) {
        vector<vector<long long>> dp(n,vector<long long>(k+1,0));
        vector<vector<long long>> pref(n,vector<long long>(k+1,0));
        for(int i=0;i<n;i++){
            dp[i][0]=1;
            pref[i][0]=i+1;
        }
        int mod=1e9+7;
        for(int i=1;i<n;i++){
            for(int j=1;j<=k;j++){
                
                dp[i][j]=dp[i-1][j];
                dp[i][j]+=pref[i-1][j-1];
                dp[i][j]%=mod;
                pref[i][j]=pref[i-1][j]+dp[i][j];
                pref[i][j]%=mod;
            }
        }
        return dp[n-1][k];
    }
};