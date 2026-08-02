class Solution {
public:
vector<vector<int>> dp;
    int dfs(int l,int r,vector<int>& prefix,vector<int>& suffix,vector<int>& stoneValue){
        if(l==r) return 0;
        if(dp[l][r]!=-1) return dp[l][r];
        int ans=0;
        for(int k=l;k<r;k++){
            int left =prefix[k]-(l>0 ? prefix[l - 1] : 0);
            int right = suffix[k+1] - (r+1<stoneValue.size() ? suffix[r+1] : 0);
            if(left<right){
                ans=max(ans,left+dfs(l,k,prefix,suffix,stoneValue));
            }else if(left>right){
                ans=max(ans,right+dfs(k+1,r,prefix,suffix,stoneValue));
            }else{
                ans=left+max(dfs(l,k,prefix,suffix,stoneValue),
                            dfs(k+1,r,prefix,suffix,stoneValue));
            }
        }
        return dp[l][r]=ans;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n=stoneValue.size();
        dp.assign(n,vector<int>(n,-1));
        vector<int> prefix(n),suffix(n);
        prefix[0]=stoneValue[0];
        suffix[n-1]=stoneValue[n-1];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+stoneValue[i];
        }
        for(int i=n-2;i>=0;i--){
            suffix[i]=suffix[i+1]+stoneValue[i];
        }
        return dfs(0,n-1,prefix,suffix,stoneValue);
    }
};