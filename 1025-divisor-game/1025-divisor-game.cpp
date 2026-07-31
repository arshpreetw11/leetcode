class Solution {
public:
    bool divisorGame(int n) {
        vector<bool> move(n+1,false);
        for(int i=2;i<=n;i++){
            for(int x=1;x<i;x++){
                if(i%x==0){
                    if(!move[i-x]){
                        move[i]=true;
                        break;
                    }
                }
            }
        }
        return move[n];
    }
};