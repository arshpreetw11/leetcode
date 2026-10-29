class Solution {
    int n;
    vector<vector<int>> adj;
    vector<int> parent, depth, heavy, head, pos, tree_val;
    vector<int> segTree;
    int cur_pos = 0;

    int dfs1(int u, int p, int d, const string& s) {
        parent[u] = p;
        depth[u] = d;
        int size = 1, max_subtree_size = 0;
        for (int v : adj[u]) {
            if (v != p) {
                int subtree_size = dfs1(v, u, d + 1, s);
                size += subtree_size;
                if (subtree_size > max_subtree_size) {
                    max_subtree_size = subtree_size;
                    heavy[u] = v;
                }
            }
        }
        return size;
    }

    void dfs2(int u, int h, const string& s) {
        head[u] = h;
        pos[u] = cur_pos;
        tree_val[cur_pos] = (1 << (s[u] - 'a'));
        cur_pos++;

        if (heavy[u] != -1) {
            dfs2(heavy[u], h, s);
        }
        for (int v : adj[u]) {
            if (v != parent[u] && v != heavy[u]) {
                dfs2(v, v, s);
            }
        }
    }

    void build(int node, int l, int r) {
        if (l == r) {
            segTree[node] = tree_val[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * node, l, mid);
        build(2 * node + 1, mid + 1, r);
        segTree[node] = segTree[2 * node] ^ segTree[2 * node + 1];
    }

    void updateTree(int node, int l, int r, int idx, int val) {
        if (l == r) {
            segTree[node] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid) updateTree(2 * node, l, mid, idx, val);
        else updateTree(2 * node + 1, mid + 1, r, idx, val);
        segTree[node] = segTree[2 * node] ^ segTree[2 * node + 1];
    }

    int queryTree(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return 0;
        if (ql <= l && r <= qr) return segTree[node];
        int mid = (l + r) / 2;
        return queryTree(2 * node, l, mid, ql, qr) ^ queryTree(2 * node + 1, mid + 1, r, ql, qr);
    }

    int queryPath(int u, int v) {
        int res = 0;
        while (head[u] != head[v]) {
            if (depth[head[u]] < depth[head[v]]) swap(u, v);
            res ^= queryTree(1, 0, n - 1, pos[head[u]], pos[u]);
            u = parent[head[u]];
        }
        if (depth[u] > depth[v]) swap(u, v);
        res ^= queryTree(1, 0, n - 1, pos[u], pos[v]);
        return res;
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        this->n = n;
        adj.assign(n, vector<int>());
        parent.assign(n, 0);
        depth.assign(n, 0);
        heavy.assign(n, -1);
        head.assign(n, 0);
        pos.assign(n, 0);
        tree_val.assign(n, 0);
        segTree.assign(4 * n, 0);
        cur_pos = 0;

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs1(0, -1, 0, s);
        dfs2(0, 0, s);
        build(1, 0, n - 1);

        vector<bool> ans;
        for (string& q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;
            if (type == "update") {
                int u;
                char c;
                ss >> u >> c;
                int new_val = (1 << (c - 'a'));
                updateTree(1, 0, n - 1, pos[u], new_val);
            } else {
                int u, v;
                ss >> u >> v;
                int mask = queryPath(u, v);
                ans.push_back(mask == 0 || (mask & (mask - 1)) == 0);
            }
        }
        return ans;
    }
};