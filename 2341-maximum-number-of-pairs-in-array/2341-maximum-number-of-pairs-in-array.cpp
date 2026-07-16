class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        //leftover = n-(2*pairs);
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int pairs=0,left=n;
        for(int i=1;i<n;i++){
            if(nums[i-1]==nums[i]){
                pairs++;
                left-=2;
                i++;
            }
        }
        return {pairs,left};
    }
};