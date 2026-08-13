class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n,vector<int>(5,0));
        for(int i=0;i<5;i++){
            dp[0][i]=1;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<5;j++){
                for(int k=j;k<5;k++){
                    dp[i][j]+=dp[i-1][k];
                }
            }
        }
        int ans=0;
        for(int j=0;j<5;j++){
            ans+=dp[n-1][j];
        }
        return ans;
    }
};