class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};

    int numRookCaptures(vector<vector<char>>& board) {
        int x=-1;
        int y=-1;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(board[i][j]=='R'){
                    x=i;
                    y=j;
                    break;
                }
            }
        }
        int cnt=0;
        for(int k=0;k<4;k++){
            int i=x+dx[k];
            int j=y+dy[k];
            while(i>=0 && i<8 && j>=0 && j<8){
                if(board[i][j]=='p'){
                    cnt++;
                    break;
                }else if(board[i][j]=='B') break;
                i=i+dx[k];
                j=j+dy[k];
            }
        }
        return cnt;
    }
};