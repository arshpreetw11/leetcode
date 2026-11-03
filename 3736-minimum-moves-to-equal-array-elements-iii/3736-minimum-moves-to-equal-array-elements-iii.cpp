class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mx=*max_element(nums.begin(),nums.end());
        int op=0;
        for(int n : nums){
            op+=mx-n;
        }
        return op;
    }
};