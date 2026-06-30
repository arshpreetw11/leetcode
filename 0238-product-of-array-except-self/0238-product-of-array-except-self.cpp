class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int pdct=1;
        for(int x: nums){
            pdct*=x;
        }
        int n=nums.size();
        vector<int> res(n);
        for(int i=0;i<n;i++){
            if(nums[i]!=0) res[i]=pdct/nums[i];
            else{
                int p=1;
                for(int j=0;j<n;j++){
                    if(i!=j) p*=nums[j];
                }
                res[i]=p;
            }
        }
        return res;
    }
};