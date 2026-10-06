class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int,int> lastRain;
        set<int> dry;
        vector<int> ans(rains.size(),-1);
        for(int i=0;i<rains.size();i++){
            int lake=rains[i];
            if(lake==0){
                dry.insert(i);
            }else{
                if(lastRain.count(lake)){
                    auto it=dry.upper_bound(lastRain[lake]);
                    if(it==dry.end()) return {};
                    ans[*it]=lake;
                    dry.erase(it);
                }
                lastRain[lake]=i;
            }
        }
        for(int i=0;i<rains.size();i++){
            if(rains[i]==0 && ans[i]==-1)
                ans[i]=1;
        }
        return ans;

    }
};