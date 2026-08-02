class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end());
        vector<pair<int,int>> q;
        int n=queries.size();
        for(int i=0;i<n;i++){
            q.push_back({queries[i],i});
        }
        sort(q.begin(),q.end());
        int j=0;
        int mx=0;
        int m=items.size();
        vector<int> ans(n);
        for(auto &[price,idx]:q){
            while(j<m && items[j][0]<=price){
                mx=max(mx,items[j][1]);
                j++;}
            ans[idx]=mx;
        }
        return ans;
    }
};