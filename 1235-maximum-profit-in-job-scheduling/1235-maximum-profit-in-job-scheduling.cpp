class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> sep;

        int n=profit.size();
        for(int i=0;i<n;i++){
            int s=startTime[i];
            int e=endTime[i];
            int p=profit[i];
            sep.push_back({s,e,p});
        }
        sort(sep.begin(),sep.end());
        vector<int> dp(n+1,0);
        //dp[i]=max(skip,take);
        
        vector<int> starts;
        for(auto &job: sep){
            starts.push_back(job[0]);
        }
        for(int i=n-1;i>=0;i--){
            int next=lower_bound(starts.begin(),starts.end(),sep[i][1])-starts.begin();
            int take=dp[next]+sep[i][2];
            int skip=dp[i+1];
            dp[i]=max(take,skip);

        }
        return dp[0];
    }
};