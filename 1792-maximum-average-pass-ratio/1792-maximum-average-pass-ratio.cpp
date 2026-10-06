class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto gain=[](int pass,int total){
            return (double)(pass+1)/(total+1)-(double)(pass)/(total);
        };
        priority_queue<pair<double,pair<int,int>>> pq;
        for(auto &c:classes){
            int pass=c[0];
            int total=c[1];

            pq.push({gain(pass,total),{pass,total}});
        }
        while(extraStudents--) {
            auto top = pq.top();
            pq.pop();

            int pass = top.second.first;
            int total = top.second.second;

            pass++;
            total++;

            pq.push({gain(pass, total), {pass, total}});
        }
        double ans=0;
        while(!pq.empty()){
            auto top = pq.top();

            int pass = top.second.first;
            int total = top.second.second;

            ans += (double)pass / total;

            pq.pop();
        }
        return ans/classes.size();
    }
};