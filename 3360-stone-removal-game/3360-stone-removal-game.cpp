class Solution {
public:
    bool canAliceWin(int n) {
        int sub=10,i=0;
        while(true){
            if(n-sub<0){
                if(i%2) return true;
                else return false;
            }else if(n-sub==0){
                if(i%2) return false;
                else return true;
            }
            n-=sub;
            sub--;
            i++;
        }
        return true;
    }
};