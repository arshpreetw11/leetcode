class Solution {
public:

    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        //offers[i]={start,end,gold};
        //ith buyer wants to buy all the houses from strat to end for gold amount;
        // n=no of houses

        sort(offers.begin(),offers.end());
        vector<vector<pair<int,int>>> endAt(n);
        for(auto offer:offers){
            int start=offer[0];
            int end=offer[1];
            int gold=offer[2];
            endAt[end].push_back({start,gold});
        }
        vector<int> dp(n+1,0);
        for(int i=0;i<n;i++){
            dp[i+1]=dp[i];
            for(auto &[start,gold]:endAt[i]){
                dp[i+1]=max(dp[i+1],dp[start]+gold);
            }
        }
        return dp[n];
    }
};