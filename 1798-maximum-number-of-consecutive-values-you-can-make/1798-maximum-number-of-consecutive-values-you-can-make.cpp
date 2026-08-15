class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(),coins.end());
        int maxReach=0;
        for(int coin: coins){
            if(coin>maxReach+1){
                break;
            }
            maxReach+=coin;
        }
        return maxReach+1;
        
    }
};