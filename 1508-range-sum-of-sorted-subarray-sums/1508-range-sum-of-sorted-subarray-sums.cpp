class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> sum;
        for(int i=0;i<n;i++){
            int s=0;
            for(int j=i;j<n;j++){
                s+=nums[j];
                sum.push_back(s);
            }
        }
        sort(sum.begin(),sum.end());
        long long ans=0;
        int mod=1e9+7;
        for(int i=left-1;i<right;i++){
            ans=(ans+sum[i])%mod;
        }
        return ans;
    }
};