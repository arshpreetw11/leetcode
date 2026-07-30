class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        
        unordered_map<int,int> freq;
        for(int x: barcodes){
            freq[x]++;
        }
        priority_queue<pair<int,int>> pq;
        
        for(auto &[num,f]:freq){
            pq.push({f,num});
        }
        vector<int> ans;
        while(pq.size()>=2){
            auto [f1,x]=pq.top();
            pq.pop();
            auto [f2,y]=pq.top();
            pq.pop();
            ans.push_back(x);
            ans.push_back(y);
            if(--f1>0) pq.push({f1,x});
            if(--f2>0) pq.push({f2,y});
        }
        if(!pq.empty()){
            ans.push_back(pq.top().second);
        }
        return ans;
    }
};