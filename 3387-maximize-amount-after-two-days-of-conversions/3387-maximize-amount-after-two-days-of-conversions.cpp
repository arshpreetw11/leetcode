class Solution {
public:
    void dfs(string node,double amount,unordered_map<string,vector<pair<string,double>>>& graph,unordered_map<string,double>& vis){
        if(vis.count(node) && vis[node]>=amount) return ;
        vis[node]=amount;
        for(auto &[nxt,amt]:graph[node]){
            dfs(nxt,amount*amt,graph,vis);
        }
    }
    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        unordered_map<string,vector<pair<string,double>>> graph1,graph2;
        for(int i=0;i<pairs1.size();i++){
            string u=pairs1[i][0];
            string v=pairs1[i][1];
            double rate=rates1[i];
            graph1[u].push_back({v,rate});
            graph1[v].push_back({u,(1.0/rate)});
        }
        for(int i=0;i<pairs2.size();i++){
            string u=pairs2[i][0];
            string v=pairs2[i][1];
            double rate=rates2[i];
            graph2[u].push_back({v,rate});
            graph2[v].push_back({u,(1.0/rate)});
        }
        
        unordered_map<string,double> day1;
        dfs(initialCurrency,1.0,graph1,day1);
        double ans=1.0;
        for(auto &[nxt,amt]:day1){
            unordered_map<string,double> day2;
            dfs(nxt,amt,graph2,day2);

            if(day2.count(initialCurrency)){
                ans=max(ans,day2[initialCurrency]);
            }
        }
        return ans;
    }
};