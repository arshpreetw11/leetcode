class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n=s.size();
        if(k==1) return n;
        vector<int> dp(n+1,0);
        for(int i=1;i<=n;i++){
            dp[i]=dp[i-1];
            for(int start=0;start<=i-k;start++){
                int l=start;
                int r=i-1;
                bool ok=true;

                while(l<r){
                    if(s[l]!=s[r]){
                        ok=false;
                        break;
                    }
                    l++;
                    r--;
                }
                if(ok){
                    dp[i]=max(dp[i],dp[start]+1);
                }
            }
        }
        return dp[n];
    }
};