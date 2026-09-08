class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        //2 largest & 1 smallest value;
        sort(nums.begin(),nums.end());
        int median=0;
        int n=nums.size();
        int loop=n/3;
        int j=n-2;
        long long sum=0;
        while(loop--){
            sum+=nums[j];
            j-=2;
        }
        return sum;
    }
};