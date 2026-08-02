class Solution {
public:
// vector<vector<int>> dp;
//     int dfs(int start,int end,vector<int>& piles){

//         if(start<0 || end>=piles.size()) return 0;
//         if(dp[start][end]!=-1) return dp[start][end];
//         if(start==end){
//             return dp[start][end]=piles[start];
//         }
//         int takeLeft=piles[start]-dfs(start+1,end,piles);
//         int takeRight=piles[end]-dfs(start,end-1,piles);
//         return dp[start][end]=max(takeLeft,takeRight);
//     }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<int> dp=piles;
        for(int len=2;len<=n;len++){
            for(int i=0;i+len-1<n;i++){
                int j=i+len-1;
                dp[i]=max(piles[i]-dp[i+1],
                        piles[j]-dp[i]);
            }
        }
        return dp[0]>0;
        
    }
};