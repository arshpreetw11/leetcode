class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    ans += 4;
                    for (int k = 0; k < 4; k++) {
                        int ni = i + dx[k];
                        int nj = j + dy[k];

                        if (ni >= 0 && ni < m &&
                            nj >= 0 && nj < n &&
                            grid[ni][nj] == 1) {
                            ans--;
                        }
                    }
                }
            }
        }
        return ans;
    }
};