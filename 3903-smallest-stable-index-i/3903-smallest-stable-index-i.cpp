class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1) return 0;
        vector<int> suffix(n);
        suffix[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i]=min(suffix[i+1],nums[i]);
        }
        int prefix=nums[0];
        for(int i=0;i<n;i++){
            prefix=max(prefix,nums[i]);
            int suff=suffix[i];
            if(prefix-suff<=k)
                return i;
        }
        
        return -1;
    }
};