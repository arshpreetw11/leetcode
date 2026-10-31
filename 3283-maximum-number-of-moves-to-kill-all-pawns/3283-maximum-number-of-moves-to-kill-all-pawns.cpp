class Solution {
public:
int dx[8]={-2,-2,-1,-1,1,1,2,2};
int dy[8]={-1,1,-2,2,-2,2,-1,1};

    int maxMoves(int kx, int ky, vector<vector<int>>& positions) {
        int n=positions.size();
        vector<vector<int>> all_points=positions;
        all_points.push_back({kx,ky});

        int total=n+1;
        vector<vector<int>> dist(total,vector<int>(total,0));
        for(int i=0;i<total;i++){
            queue<pair<int,int>> q;
            vector<vector<int>> d(50,vector<int>(50,-1));
            q.push({all_points[i][0],all_points[i][1]});
            d[all_points[i][0]][all_points[i][1]]=0;

            while(!q.empty()){
                auto [r,c]=q.front();
                q.pop();
                for(int i=0;i<8;i++){
                    int nr=r+dx[i];
                    int nc=c+dy[i];
                    if (nr >= 0 && nr < 50 && nc >= 0 && nc < 50 && d[nr][nc] == -1){
                        d[nr][nc]=d[r][c]+1;
                        q.push({nr,nc});
                    }
                }
                
            }
            for (int j = 0; j < total; ++j) {
                dist[i][j] = d[all_points[j][0]][all_points[j][1]];
            }
        }
        vector<vector<int>> dp(total,vector<int>(1<<n,-1));
        auto solve = [&](auto& self, int curr_idx, int mask) -> int {
            if (mask == 0) return 0;
            if (dp[curr_idx][mask] != -1) return dp[curr_idx][mask];
            
            int pawns_captured = n - __builtin_popcount(mask);
            bool is_alice = (pawns_captured % 2 == 0);
            
            int best_score = is_alice ? -1e9 : 1e9;
            
            for (int i = 0; i < n; ++i) {
                if ((mask & (1 << i)) != 0) {
                    int travel_cost = dist[curr_idx][i];
                    int next_mask = mask ^ (1 << i);
                    int score = travel_cost + self(self, i, next_mask);
                    
                    if (is_alice) {
                        best_score = max(best_score, score);
                    } else {
                        best_score = min(best_score, score);
                    }
                }
            }
            
            return dp[curr_idx][mask] = best_score;
        };
        return solve(solve, n, (1 << n) - 1);
    }
};