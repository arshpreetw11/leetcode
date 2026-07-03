class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ways=0;
        if(nums.size()==1) return 0;
        int mn=*min_element(nums.begin(),nums.end());
        for(int n:nums){
            ways+=n-mn;
        }
        return ways;
    }
};