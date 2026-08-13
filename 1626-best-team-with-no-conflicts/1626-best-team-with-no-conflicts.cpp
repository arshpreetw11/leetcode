class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        unordered_map<int,vector<int>> mp;
        vector<pair<int,int>> combine;
        int n=ages.size();
        for(int i=0;i<n;i++){
            mp[ages[i]].push_back(scores[i]);
            combine.push_back({ages[i],scores[i]});
        }
        sort(combine.begin(),combine.end());
        vector<int> dp(n);
        int ans=0;
        for(int i=0;i<n;i++){
            dp[i]=combine[i].second;
            for(int j=0;j<i;j++){
                if(combine[j].second<=combine[i].second){
                    dp[i]=max(dp[i],dp[j]+combine[i].second);
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};