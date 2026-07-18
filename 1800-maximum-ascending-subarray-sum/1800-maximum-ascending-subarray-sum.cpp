class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n,0);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i-1]<nums[i]){
                prefix[i]=nums[i]+prefix[i-1];
            }else{
                prefix[i]=nums[i];
            }
        }
        return *max_element(prefix.begin(),prefix.end());
    }
};