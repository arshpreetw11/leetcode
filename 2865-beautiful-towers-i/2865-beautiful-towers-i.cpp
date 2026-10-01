class Solution {
public:
    long long maximumSumOfHeights(vector<int>& heights) {
        int n=heights.size();
        long long mx=0;
        for(int i=0;i<n;i++){
            int peak=heights[i];
            vector<int> nums=heights;
            for(int j=i-1;j>=0;j--){
                nums[j]=min(nums[j],nums[j+1]);
            }
            for(int j=i+1;j<n;j++){
                nums[j]=min(nums[j],nums[j-1]);
            }
            long long sum=0;
            for(int x:nums){
                sum+=x;
            }
            if(mx<sum) mx=sum;
        }
        return mx;
    }
};