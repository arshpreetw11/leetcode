class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int X=0,O=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[i][j]=='X') X++;
                else if(board[i][j]=='O') O++;
            }
        }
        auto win=[&](char c){
            for(int i=0;i<3;i++){
                if(board[i][0]==c && 
                   board[i][1]==c &&
                   board[i][2]==c) return true;
            }
            for(int i=0;i<3;i++){
                if(board[0][i]==c && 
                   board[1][i]==c &&
                   board[2][i]==c) return true;
            }
            if(board[0][0]==c &&
               board[1][1]==c &&
               board[2][2]==c) return true;
            
            if(board[2][0]==c &&
               board[1][1]==c &&
               board[0][2]==c) return true;
            
            return false;
        };
        bool xwin=win('X');
        bool owin=win('O');


        if(X!=O && X!=O+1) return false;
        if(xwin && owin) return false;
        if(xwin && X!=O+1) return false;
        if(owin && X!=O) return false;
        return true;
    }
};