class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int max_days=*max_element(days.begin(),days.end())+1;
        sort(days.begin(),days.end());
        unordered_set<int> day(days.begin(),days.end());
        vector<int> dp(max_days,0);
        for(int i=1;i<max_days;i++){
            if(!day.count(i)){
                dp[i]=dp[i-1];
            }
            else{
                //minimum of day-1 pass , day-7 pass , day-30 pass;
                int day1,day7,day30;
                if(i>0)
                    day1=dp[i-1]+costs[0];
                
                    day7=dp[max(0,i-7)]+costs[1];
                
                    day30=dp[max(0,i-30)]+costs[2];
                dp[i]=min({day1,day7,day30});
            }
        }
        return dp[max_days-1];
    }
};