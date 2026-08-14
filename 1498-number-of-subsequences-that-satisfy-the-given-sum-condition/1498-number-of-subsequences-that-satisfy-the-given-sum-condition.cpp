class Solution {
public:
    const int mod=1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int left=0;
        int right=n-1;
        vector<int> power(n,1);
        for(int i=1;i<n;i++){
            power[i]=(2LL*power[i-1])%mod;
        }

        long long ans=0;
        while(left<=right){
            if(nums[left]+nums[right]<=target){
                ans+=power[right-left];
                ans%=mod;
                left++;
            }
            else{
                right--;
            }
        }
        return ans;
    }
};