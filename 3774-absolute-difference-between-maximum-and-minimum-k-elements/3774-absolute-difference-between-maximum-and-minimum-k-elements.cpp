class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        int mx=0;
        int mn=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<k;i++){
            mn+=nums[i];
        }
        sort(nums.begin(),nums.end(),greater<int>());
        for(int i=0;i<k;i++){
            mx+=nums[i];
        }
        return abs(mx-mn);
    }
};