class Solution {
public:
vector<string> ans;
    void dfs(string u,unordered_map<string, priority_queue<
            string,vector<string>,greater<string>>>& adj) {
        while (!adj[u].empty()) {
            string v = adj[u].top();
            adj[u].pop();
            dfs(v,adj);
        }
        ans.push_back(u);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n=tickets.size();
        sort(tickets.begin(),tickets.end(),[&](vector<string>&a,vector<string>&b){
            return a[0] < b[0];
        });
        unordered_map<string, priority_queue<
            string,
            vector<string>,
            greater<string>
        >> adj;
        for(int i=0;i<n;i++){
            string from=tickets[i][0];
            string to =tickets[i][1];
            adj[from].push(to);
        }
        dfs("JFK",adj);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};