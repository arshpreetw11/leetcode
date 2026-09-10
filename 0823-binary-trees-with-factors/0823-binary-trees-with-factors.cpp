class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        //binary tree-> two children's
        long long ans=0;
        sort(arr.begin(),arr.end());
        int n=arr.size();
        unordered_map<int,long long> dp;
        for(int x:arr){
            dp[x]=1;
        }
        int mod=1e9+7;
        for(int i=0;i<n;i++){
            int x=arr[i];
            for(int j=0;j<i;j++){
                int a=arr[j];
                if(x%a) continue;
                int b=x/a;
                if(dp.count(b)){
                    dp[x]=(dp[x]+dp[a]*dp[b])%mod;
                }
            }
            ans=(ans+dp[x])%mod;
        }
        return ans;
    }
};