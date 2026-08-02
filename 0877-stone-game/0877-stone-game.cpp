class Solution {
public:
vector<vector<int>> dp;
    int dfs(int start,int end,vector<int>& piles){

        if(start<0 || end>=piles.size()) return 0;
        if(dp[start][end]!=-1) return dp[start][end];
        if(start==end){
            return dp[start][end]=piles[start];
        }
        int takeLeft=piles[start]-dfs(start+1,end,piles);
        int takeRight=piles[end]-dfs(start,end-1,piles);
        return dp[start][end]=max(takeLeft,takeRight);
    }
    bool stoneGame(vector<int>& piles) {
        dp.assign(piles.size(),vector<int>(piles.size(),-1));
        return dfs(0,piles.size()-1,piles)>0;
    }
};