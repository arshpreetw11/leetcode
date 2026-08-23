class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int leaf=arr.size();
        int n=leaf;
        if(leaf==0) return 0;
        if(leaf==2){
            return arr[0]*arr[1];
        }
        int nodes=leaf-1;//nodes for sum;
        vector<vector<int>> dp(n,vector<int>(n,0));
        vector<vector<int>> mx(n,vector<int>(n,0));
        for(int i=0;i<leaf;i++){
            mx[i][i]=arr[i];
        }
        for(int len=2;len<=leaf;len++){
            for(int l=0;l+len<=leaf;l++){
                int r=l+len-1;
                dp[l][r]=INT_MAX;
                for(int k=l;k<r;k++){
                    mx[l][r]=max(mx[l][r],max(mx[l][k],mx[k+1][r]));
                    dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]+mx[l][k]*mx[k+1][r]);
                }
            }
        }
        return dp[0][leaf-1];
    }
};