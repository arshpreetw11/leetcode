class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int mx=1;
        int i=0;
        while(i<nums.size()){
            int x=nums[i];
            int j=i;
            int len=1;
            while(j<nums.size()-1 && nums[j]<nums[j+1]){
                j++;
                len++;
            }
            mx=max(mx,len);
            i=j+1;
        }
        return mx;
    }
};