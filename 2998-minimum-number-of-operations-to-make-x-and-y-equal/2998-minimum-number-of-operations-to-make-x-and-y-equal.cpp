class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        if(y>=x) return y-x;
        queue<pair<int,int>> q;
        unordered_set<int> vis;
        q.push({x,0});
        vis.insert(x);
        int LIMIT = 2 * max(x, y);
        int mn=INT_MAX;
        while(!q.empty()){
            auto [val,steps]=q.front();
            q.pop();
            if(val==y) return steps;
            if (val % 11 == 0) {
                int nxt = val / 11;
                if (!vis.count(nxt)) {
                    vis.insert(nxt);
                    q.push({nxt, steps + 1});
                }
            }

            if (val % 5 == 0) {
                int nxt = val / 5;
                if (!vis.count(nxt)) {
                    vis.insert(nxt);
                    q.push({nxt, steps + 1});
                }
            }
            if (val + 1 <= LIMIT && !vis.count(val + 1)) {
                vis.insert(val + 1);
                q.push({val + 1, steps + 1});
            }
            if (val - 1 >= 0 && !vis.count(val - 1)) {
                vis.insert(val - 1);
                q.push({val - 1, steps + 1});
            }
        }
        return -1;
    }
};