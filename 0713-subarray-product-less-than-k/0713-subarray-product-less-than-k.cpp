class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int cnt=0;
        int n=nums.size();
        for(int j=0;j<n;j++){
            int p=1;
            int i=j;
            while(i>=0 && p*nums[i]<k){
                p=p*nums[i];
                i--;
                cnt++;
            }
        }
        return cnt;
    }
};