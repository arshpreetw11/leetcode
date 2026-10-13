class Solution {
public:
    int minDistance(vector<int>& houses, int k) {
        int n=houses.size();
        if(n<=k) return 0;
        sort(houses.begin(), houses.end());
        if(k==1){
            int idx=(n)/2;
            int val=houses[idx];
            
            int sum=0;
            for(int x:houses){
                sum+=abs(x-val);
            }
            return sum;
        }
        vector<vector<int>> cost(n,vector<int>(n,0));
        for(int l=0;l<n;l++){
            for(int r=l;r<n;r++){
                int mid=(l+r)/2;
                for(int x=l;x<=r;x++){
                    cost[l][r]+=abs(houses[x]-houses[mid]);
                }
            }
        }
        int INF=1e9;
        vector<vector<int>> dp(n+1,vector<int>(k+1,INF));
        dp[0][0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){
                for(int p=j-1;p<i;p++){
                    dp[i][j]=min(dp[i][j],dp[p][j-1]+cost[p][i-1]);
                }
            }
        }
        return dp[n][k];
    }
};