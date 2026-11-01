class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int op=0;
        for(int n:nums){
            if(n%3) op++;
        }
        return op;
    }
};