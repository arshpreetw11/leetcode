class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int> mp;

        for(int i=0;i<arr.size();i++){
            mp[arr[i]]=i;
        }
        vector<vector<int>> dp(n,vector<int>(n,2));
        int mx=0;
        for(int j=0;j<n;j++){
            for(int i=0;i<j;i++){
                int target=arr[j]-arr[i];
                if(mp.count(target)){
                    int k=mp[target];
                    if(k<i){
                        dp[i][j]=dp[k][i]+1;
                    }
                }
                if(dp[i][j]>2){
                    mx=max(mx,dp[i][j]);
                }
            }
        }
        return (mx>=3)?mx:0;
    }
};