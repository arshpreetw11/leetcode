class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int start=1;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        vector<vector<int>> t;
        for(int i=0;i<tasks.size();i++){
            t.push_back({tasks[i][0],tasks[i][1],i});
        }
        sort(t.begin(),t.end());
        vector<int> ans;
        int n=tasks.size();
        long long time=0;
        int i=0;
        while(i<n || !pq.empty()){
            if(pq.empty())
            time=max(time,(long long)t[i][0]);

            while(i<n && t[i][0]<=time){
                pq.push({t[i][1],t[i][2]});
                i++;
            }
            auto [p,idx]=pq.top();
            pq.pop();
            ans.push_back(idx);
            time+=p;
        }
        return ans;
    }
};