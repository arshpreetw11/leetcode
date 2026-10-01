class Solution {
public:
    int minOperations(vector<string>& logs) {
        int move=0;
        for(int i=0;i<logs.size();i++){
            if(logs[i]=="./") continue;
            else if(logs[i]=="../"){
                if(move!=0) move--; 
            }
            else{
                move++;
            }
        }
        return move;
    }
};