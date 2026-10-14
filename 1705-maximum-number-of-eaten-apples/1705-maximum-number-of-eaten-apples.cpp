class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int n=apples.size();
        int i=0,apple=0;
        while(i<n || !pq.empty()){
            if(i<n && apples[i]>0){
                pq.push({i+days[i],apples[i]});
            }
            while(!pq.empty() && pq.top().first<=i){
                pq.pop();
            }
            if(!pq.empty()){
                auto [d,a]=pq.top();
                pq.pop();
                if(a>1) pq.push({d,a-1});
                apple++;
            }
            i++;
        }
        return apple;
    }
};