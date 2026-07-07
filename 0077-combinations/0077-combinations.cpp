class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;
    void solve(int start, int n, int k) {
        if (cur.size() == k) {
            res.push_back(cur);
            return;
        }

        for (int i = start; i <= n; i++) {
            cur.push_back(i);
            solve(i + 1, n, k);
            cur.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        solve(1,n,k);
        return res;
    }
};