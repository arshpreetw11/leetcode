class Solution {
public:
    int reachNumber(int target) {
        target=abs(target);
        int sum=0;
        int turn=0;
        while(sum<target || (sum-target)%2){
            turn++;
            sum+=turn;
        }
        return turn;
    }
};