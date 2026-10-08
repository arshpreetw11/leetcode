class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int total=0;
        for(int n:stones)
            total+=n;
        int target=total/2;
        vector<int> dp(target+1,0);
        for(int x:stones){
            for(int j=target;j>=x;j--){
                dp[j]=max(dp[j],dp[j-x]+x);
            }
        }
        return total-2*dp[target];
    }
};