class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<double> prefix(n+1,0.0);
        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+nums[i];
        } 
        vector<vector<double>> dp(n + 1, vector<double>(k + 1, 0.0));
        for (int i = 1; i <= n; i++) {
            dp[i][1] = prefix[i] / i;
        }
        for(int l=2;l<=k;l++){
            for(int i=l;i<=n;i++){
                for(int j=l-1;j<i;j++){
                    double avg = (prefix[i] - prefix[j]) / (i - j);
                    dp[i][l] = max(dp[i][l],
                                dp[j][l - 1] + avg);
                }
            }
        }
        return dp[n][k];
    }
};