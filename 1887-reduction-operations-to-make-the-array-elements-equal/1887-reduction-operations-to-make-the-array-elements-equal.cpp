class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        int n=nums.size();
        int op=0;
        for(int i=1;i<n;i++){
            if(nums[i-1]!=nums[i]) op+=i;
        }
        return op;
    }
};