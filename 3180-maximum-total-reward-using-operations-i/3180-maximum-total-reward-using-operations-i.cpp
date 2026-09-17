class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        int n=rewardValues.size();
        sort(rewardValues.begin(),rewardValues.end());
        int m=2*rewardValues[n-1];
        vector<bool> dp(m,false);
        dp[0]=true;
        for(int x:rewardValues){
            for(int s=m-1;s>=0;s--){
                if(dp[s] && s<x){
                    dp[s+x]=true;
                }
            }
        }
        for(int s=m-1;s>=0;s--){
            if(dp[s]) return s;
        }
        return 0;
    }
};