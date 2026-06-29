class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int mxLen=0;
        for(int i=0;i<n;i++){
            int mn=nums[i],mx=nums[i];
            for(int j=i+1;j<n;j++){
                mx=max(mx,nums[j]);
                mn=min(mn,nums[j]);
                int diff=mx-mn;
                if(diff==1){
                    mxLen=max(mxLen,j-i+1);
                }
            }
        }
        return mxLen;
    }
};