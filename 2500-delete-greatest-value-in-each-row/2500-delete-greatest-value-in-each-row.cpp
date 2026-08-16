class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();

        for (auto &r : grid) {
            sort(r.begin(), r.end());
        }
        int ans=0;
        for(int c=0;c<col;c++){
            int mx = 0;

            for (int r = 0; r < row; r++) {
                mx = max(mx, grid[r][c]);
            }
            ans+=mx;
        }
        return ans;
    }
};