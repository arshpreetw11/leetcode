class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<pair<int,int>>> adj;
    vector<int> ans;
    void dfs(int u) {
        for (auto &[v, factor] : adj[u]) {
            ans[v] = (1LL * ans[u] * factor) % MOD;
            dfs(v);
        }
    }
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        int n = conversions.size() + 1;
        adj.assign(n, {});
        ans.assign(n, 0);
        for (auto &e : conversions) {
            int u = e[0];
            int v = e[1];
            int f = e[2];
            adj[u].push_back({v, f});
        }
        ans[0] = 1;
        dfs(0);
        return ans;
    }
};