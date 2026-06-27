class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans=0;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int len=1;
        if(n==0) return 0;
        
        for(int i=1;i<n;i++){
            if(nums[i-1]==nums[i]) continue;
            if(nums[i-1]+1==nums[i]) len++;
            else{
                ans=max(ans,len);
                len=1;
            }
        }
        ans=max(ans,len);
        return ans;
    }
};