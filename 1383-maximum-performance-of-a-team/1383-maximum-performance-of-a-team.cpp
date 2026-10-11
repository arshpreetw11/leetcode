class Solution {
public:
int mod=1e9+7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<vector<int>> se;
        for(int i=0;i<n;i++){
            int s=speed[i];
            int e=efficiency[i];
            se.push_back({s,e});
        }
        sort(se.begin(),se.end(),[&](const vector<int>& a,const vector<int>& b){
            return a[1]>b[1];
        });
        priority_queue<int, vector<int>, greater<int>> pq;
        long long ans=0;
        long long sum=0;
        for(int i=0;i<n;i++){
            int s=se[i][0];
            int e=se[i][1];
            pq.push(s);
            sum+=s;
            if(pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            ans=max(ans,sum*e);
        }
        return ans%mod;
    }
};