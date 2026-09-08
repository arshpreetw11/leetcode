class Solution {
public:
    int lastRemaining(int n) {
        if(n<=2) return n;
        //left to right and right to left;
        int head=1;
        int steps=1;
        bool left=true;
        while(n>1){
            if(left || n%2){
                head+=steps;
            }
            n/=2;
            steps*=2;
            left=!left;
        }
        return head;
    }
};