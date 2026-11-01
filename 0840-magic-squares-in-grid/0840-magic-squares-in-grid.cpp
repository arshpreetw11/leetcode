class Solution {
public:
    bool isMagic(vector<vector<int>>& grid,int r,int c){
        vector<int> seen(10,false);
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                int val=grid[i+r][j+c];
                if(val<=0 || val>=10 || seen[val]) return false;
                seen[val]=true;
            }
        }
        for(int i=0;i<3;i++){
            if(grid[r][c+i]+grid[r+1][c+i]+grid[r+2][c+i]!=15) return false;
            if(grid[r+i][c]+grid[r+i][c+1]+grid[r+i][c+2]!=15) return false;
        }
        if(grid[r][c]+grid[r+1][c+1]+grid[r+2][c+2]!=15) return false;
        if(grid[r][c+2]+grid[r+1][c+1]+grid[r+2][c]!=15) return false;
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        if(m<3 || n<3) return 0;
        int cnt=0;
        for(int i=0;i<m-2;i++){
            for(int j=0;j<n-2;j++){
                if(isMagic(grid,i,j)) cnt++;
            }
        }
        return cnt;
    }
};