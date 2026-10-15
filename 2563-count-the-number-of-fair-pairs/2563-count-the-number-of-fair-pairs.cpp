class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        long long cnt=0;
        for(int i=0;i<n;i++){
            int u=upper-nums[i];
            int l=lower-nums[i];
            auto left = lower_bound(nums.begin() + i + 1,
                                    nums.end(), l);
            auto right = upper_bound(nums.begin() + i + 1,
                                     nums.end(), u);
            cnt+=right-left;
        }
        return cnt;
        
    }
};