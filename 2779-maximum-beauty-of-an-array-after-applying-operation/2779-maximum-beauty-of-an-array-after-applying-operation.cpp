class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        // i--> nums[i]---> [nums[i]-k , nums[i]+k];
        int n=nums.size();
        // num in range => [nums[i]-k,nums[i]+k];
        sort(nums.begin(),nums.end());
        int max_len=1;
        int left=0;
        for(int r=0;r<n;r++){
            while(nums[r]-nums[left]>2*k){
                left++;
            }
            max_len=max(max_len,r-left+1);
        }
        return max_len;
    }
};