class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();
        int mn=INT_MAX;
        for(int sz=l;sz<=r;sz++){
            for(int i=0;i<=n-sz;i++){
                int j=i;
                int sum=0;
                int s=0;
                while(j<n && s<sz){
                    sum+=nums[j];
                    j++;
                    s++;
                }
                if(sum>0) mn=min(mn,sum);
            }
        }
        return mn==INT_MAX?-1:mn;
    }
};