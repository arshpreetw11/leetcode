class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        for(int i=0;i<nums.size();i++){
            sort(nums[i].begin(),nums[i].end());
        }
        int sum=0;
        for(int j=0;j<nums[0].size();j++){
            int mx=0;
            for(int i=0;i<nums.size();i++){
                mx=max(mx,nums[i][j]);
            }
            sum+=mx;
        }
        return sum;
    }
};