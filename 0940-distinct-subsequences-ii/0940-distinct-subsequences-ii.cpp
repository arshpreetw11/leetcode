class Solution {
public:
    int distinctSubseqII(string s) {
        int n=s.size();
        vector<int> dp(n+1),last(26,-1);
        dp[0]=1;
        int mod=1e9+7;
        for(int i=1;i<=n;i++){
            int c=s[i-1]-'a';
            dp[i]=(2*dp[i-1])%mod;
            if(last[c]!=-1) dp[i]=(dp[i]-dp[last[c]-1])%mod;
            last[c]=i;
            
        }
        return (dp[n]-1+mod)%mod;
    }
};