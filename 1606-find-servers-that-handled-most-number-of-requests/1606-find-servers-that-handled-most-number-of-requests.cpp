class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n=arrival.size();
        vector<int> count(k);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        set<int> available;
        for(int i=0;i<k;i++){
            available.insert(i);
        }
        for(int i=0;i<n;i++){
            int start=arrival[i],end=load[i];
            while(!pq.empty() && pq.top().first<=start){
                available.insert(pq.top().second);
                pq.pop();
            }
            if(available.size()==0)
                continue;
            auto it=available.lower_bound(i%k);
            int ind=0;
            if(it==available.end())
                ind=*available.begin();
            else ind=*it;
            available.erase(ind);
            pq.emplace(start+end,ind);
            count[ind]++;
        }
        int mx=*max_element(count.begin(),count.end());
        vector<int> ans;
        for(int i=0;i<k;i++){
            if(count[i]==mx) ans.push_back(i);
        }
        return ans;
    }
};