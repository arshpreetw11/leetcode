class Solution {
public:
    bool dfs(string curr,string target,unordered_map<string,bool>& vis,unordered_map<string, vector<pair<string,double>>>& graph,double product,double &ans){
        vis[curr]=true;
        if(curr==target){
            ans=product;
            return true;
        }
        
        for(auto &g:graph[curr]){
            string nxt=g.first;
            double wt=g.second;
            if(!vis[nxt]){
                if(dfs(nxt,target,vis,graph,product*wt,ans)){
                    return true;
                }
            }
        }
        return false;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        unordered_map<string, vector<pair<string,double>>> graph;
        
        for(int i=0;i<equations.size();i++){
            string u=equations[i][0];
            string v=equations[i][1];
            double wt=values[i];
            graph[u].push_back({v,wt});
            graph[v].push_back({u,(1.0/wt)});
        }
        vector<double> res;
        for(auto &q:queries){
            string num=q[0];
            string den=q[1];
            if(!graph.count(num) || !graph.count(den)){
                res.push_back(-1.0);
                continue;
            }
            if(num==den) {
                res.push_back(1);
                continue;
            }
            unordered_map<string,bool> vis;
            double ans=1.0;
            if(dfs(num,den,vis,graph,1.0,ans)){
                res.push_back(ans);
            }else{
                res.push_back(-1.0);
            }
        }
        return res;
    }
};