class Solution {
public:
    int getdegree(int m, int c, int turn, vector<vector<int>>& graph) {
        if (turn == 0) {
            return graph[m].size();
        }

        int cnt = 0;
        for (int x : graph[c]) {
            if (x != 0)
                cnt++;
        }
        return cnt;
    }

    void addInitial(
        vector<vector<vector<int>>>& color,
        queue<array<int,3>>& q,
        int n
    ) {
        for (int c = 0; c < n; c++) {
            for (int turn = 0; turn < 2; turn++) {
                color[0][c][turn] = 1;
                q.push({0, c, turn});
            }
        }

        for (int m = 0; m < n; m++) {
            for (int turn = 0; turn < 2; turn++) {
                color[m][m][turn] = 2;
                q.push({m, m, turn});
            }
        }
    }

    vector<array<int,3>> getParent(
        int m,
        int c,
        int turn,
        vector<vector<int>>& graph
    ) {
        vector<array<int,3>> parent;

        if (turn == 0) {
            for (int p : graph[c]) {
                if (p == 0)
                    continue;
                parent.push_back({m, p, 1});
            }
        } else {
            for (int p : graph[m]) {
                parent.push_back({p, c, 0});
            }
        }

        return parent;
    }

    void processParent(
        int pm,
        int pc,
        int pturn,
        int winner,
        vector<vector<vector<int>>>& color,
        vector<vector<vector<int>>>& degree,
        queue<array<int,3>>& q
    ) {
        if (color[pm][pc][pturn] != 0)
            return;

        int current = (pturn == 0) ? 1 : 2;

        if (winner == current) {
            color[pm][pc][pturn] = winner;
            q.push({pm, pc, pturn});
        } else {
            degree[pm][pc][pturn]--;

            if (degree[pm][pc][pturn] == 0) {
                color[pm][pc][pturn] =
                    (current == 1 ? 2 : 1);

                q.push({pm, pc, pturn});
            }
        }
    }

    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<vector<vector<int>>> color(
            n,
            vector<vector<int>>(n, vector<int>(2, 0))
        );

        vector<vector<vector<int>>> degree(
            n,
            vector<vector<int>>(n, vector<int>(2, 0))
        );

        queue<array<int,3>> q;

        for (int m = 0; m < n; m++) {
            for (int c = 0; c < n; c++) {
                degree[m][c][0] = getdegree(m, c, 0, graph);
                degree[m][c][1] = getdegree(m, c, 1, graph);
            }
        }

        addInitial(color, q, n);

        while (!q.empty()) {
            auto [m, c, turn] = q.front();
            q.pop();

            int winner = color[m][c][turn];

            vector<array<int,3>> parents =
                getParent(m, c, turn, graph);

            for (auto [pm, pc, pturn] : parents) {
                processParent(
                    pm,
                    pc,
                    pturn,
                    winner,
                    color,
                    degree,
                    q
                );
            }
        }

        return color[1][2][0];
    }
};