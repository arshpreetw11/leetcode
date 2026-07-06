class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<pair<int,int>> start;
        for(int i=0;i<n;i++){
            start.push_back({intervals[i][0],i});
        }
        sort(start.begin(),start.end());
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int end=intervals[i][1];
            auto it = lower_bound(
                start.begin(),
                start.end(),
                make_pair(end, -1)
            );
            if(it==start.end()) ans[i]=-1;
            else ans[i]=it->second;
        }
        return ans;
    }
};