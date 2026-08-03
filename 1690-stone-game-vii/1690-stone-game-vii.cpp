class Solution {
public:
    vector<vector<int>> dp;
    int dfs(vector<int>& stones,int l,int r,vector<int>& prefix){
        //base Case:

        if(l==r) return dp[l][r]=0;
        if(dp[l][r]!=-1) return dp[l][r];
        int left=prefix[r]-prefix[l];
        int right=prefix[r-1]-(l?prefix[l-1]:0);
        return dp[l][r]=max(left-dfs(stones,l+1,r,prefix),
                   right-dfs(stones,l,r-1,prefix));
    }
    int stoneGameVII(vector<int>& stones) {
        int n=stones.size();
        dp.assign(n,vector<int>(n,-1));
        vector<int> prefix(n);
        prefix[0]=stones[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+stones[i];
        }

        return dfs(stones,0,n-1,prefix);
    }
};