class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> temp(m,vector<int>(n,0));
        int dx[8]={-1,-1,0,1,1,1,0,-1};
        int dy[8]={0,1,1,1,0,-1,-1,-1};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int live=0;
                for(int k=0;k<8;k++){
                    int nx=i+dx[k];
                    int ny=j+dy[k];
                    if(nx>=0 && ny>=0 && nx<m && ny<n){
                        if(board[nx][ny]==1) live++;
                    }
                }
                if(board[i][j]){
                    if(live<2){
                        temp[i][j]=0;
                    }
                    else if(live==2 || live==3){
                        temp[i][j]=1;
                    }
                    else {
                        temp[i][j]=0;
                    }
                }
                else{
                    if(live==3){
                        temp[i][j]=1;
                    }
                }
            }
        }
        board=temp;
    }
};