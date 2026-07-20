class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> res(m,vector<int>(n,0));
        for(int x=0;x<k;x++){
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==m-1 && j==n-1){
                    res[0][0]=grid[i][j];
                } else if(j==n-1){
                    res[i+1][0]=grid[i][j];
                } else{
                    res[i][j+1]=grid[i][j];
                }
            }
        }
        grid=res;}
        return grid;
    }
};