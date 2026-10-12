class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int n=nums.size();
        int mod=1e9+7;
        long long ans=0;
        vector<int> cnt(31,0);
        for(int x:nums){
            for(int bit=0;bit<31;bit++){
                if(x & (1<<bit)) cnt[bit]++;
            }
        }
        for(int c=0;c<k;c++){
            int cur=0;
            for(int bit=0;bit<31;bit++){
                if(cnt[bit]>0){
                    cur|=(1<<bit);
                    cnt[bit]--;
                }
            }
            ans=(ans+1LL*cur*cur)%mod;
        }
        return ans%mod;
    }
};