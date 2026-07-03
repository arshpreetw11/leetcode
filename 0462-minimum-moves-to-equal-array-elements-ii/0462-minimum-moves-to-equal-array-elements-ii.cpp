class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=n/2;
        int mn=nums[i];
        int ans=0;
        for(int j=0;j<n;j++){
            ans+=abs(nums[j]-mn);

        }
        return ans;
    }
};