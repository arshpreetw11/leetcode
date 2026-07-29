class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int even=0,odd=0;
        for(int n: position){
            if(n%2) odd++;
            else even++;
        }
        return min(odd,even);
    }
};