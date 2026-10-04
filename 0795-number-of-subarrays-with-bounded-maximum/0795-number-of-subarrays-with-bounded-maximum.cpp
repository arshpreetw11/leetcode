class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n=nums.size();
        int ans=0;
        int lastInvalid=-1;
        int lastValid=-1;
        for(int i=0;i<n;i++){
            if(nums[i]>right) lastInvalid=i;
            if(nums[i]>=left) lastValid=i;

            ans+=lastValid-lastInvalid;
        }
        return ans;
    }
};