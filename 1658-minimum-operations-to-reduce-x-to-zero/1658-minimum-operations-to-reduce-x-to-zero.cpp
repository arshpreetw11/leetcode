class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long target=accumulate(nums.begin(),nums.end(),0LL)-x;
        long long sum=0;
        int left=0;
        int maxLen=-1;

        for(int right=0;right<nums.size();right++){
            sum+=nums[right];
            while(sum>target && right>=left){
                sum-=nums[left++];
            }
            if(sum==target)
                maxLen=max(maxLen,right-left+1);
        }
        if(maxLen==-1) return -1;
        return nums.size()-maxLen;
    }
};