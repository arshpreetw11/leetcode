class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(),logs.end(),[&](vector<int> a,vector<int> b){
            if(a[1]==b[1]) return a[0]<b[0];
            return a[1]<b[1];
        });
        int q=queries.size();
        vector<pair<int,int>> arr;
        for(int i=0;i<q;i++){
            arr.push_back({queries[i],i});
        }
        sort(arr.begin(),arr.end());

        vector<int> ans(q,0);
        vector<int> freq(n+1,0);
        int l=0,r=0;
        int cnt=0;

        for(auto &[time,idx]:arr){
            int low=time-x;
            int high=time;

            while(r<logs.size() && logs[r][1]<=high){
                int id=logs[r][0];
                if(freq[id]==0) cnt++;
                freq[id]++;
                r++;
            }
            while(l<r && logs[l][1]<low){
                int id=logs[l][0];
                freq[id]--;
                if(freq[id]==0) cnt--;
                l++;
            }
            ans[idx]=n-cnt;
        }
        return ans;
    }
};